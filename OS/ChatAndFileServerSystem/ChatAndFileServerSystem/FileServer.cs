using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net;
using System.Net.Sockets;
using System.IO;
using System.Threading;

namespace ChatAndFileServerSystem
{
    class FileServer
    {
        Socket serverSocket;
        string storagePath;

        public void Start()
        {
            Console.Clear();
            Console.Write("Enter port : ");
            string input = Console.ReadLine();
            int port = Convert.ToInt32(input);
            IPEndPoint ipEnd = new IPEndPoint(IPAddress.Any, port);
            serverSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.IP);
            serverSocket.Bind(ipEnd);
            serverSocket.Listen(100);
            Console.Write("Enter path of storage : ");
            storagePath = Console.ReadLine();
            Console.WriteLine("Server Started");
            while (true)
            {
                Socket clientSocket = serverSocket.Accept();
                Console.WriteLine("New Client Connected");
                HandleFileClient client = new HandleFileClient();
                client.StartClient(clientSocket,storagePath);
            }
        }
    }

    class HandleFileClient
    {
        Socket clientSocket;
        string storagePath;
        public void StartClient(Socket inClientSocket,string inStoragePath)
        {
            this.clientSocket = inClientSocket;
            this.storagePath = inStoragePath;
            Thread ctThread = new Thread(ServeClient);
            ctThread.Start();
        }

        private void ServeClient()
        {
            while (true)
            {
                byte[] clientChoiceByte = new byte[1024];
                clientSocket.Receive(clientChoiceByte);
                int chosenOption = BitConverter.ToInt32(clientChoiceByte, 0);
                if (chosenOption == 1)
                    UploadServer();
                else if (chosenOption == 2)
                    DownloadServer();
                else if (chosenOption == 3)
                    ListServer();
                else if (chosenOption == 4)
                    SearchServer();
                else if (chosenOption == 5)
                {
                    Console.WriteLine(clientSocket.RemoteEndPoint.ToString() + " disconnected");
                    break;
                }
            }
        }

        private void UploadServer()
        {
            byte[] clientData = new byte[1024 * 5000];
            int receivedBytesLen = clientSocket.Receive(clientData);
            int fileNameLen = BitConverter.ToInt32(clientData, 0);
            string fileName = Encoding.ASCII.GetString(clientData, 4, fileNameLen);
            Console.WriteLine("Client:{0} connected & File {1} started received.", clientSocket.RemoteEndPoint, fileName);
            BinaryWriter bWrite = new BinaryWriter(File.Open(storagePath + fileName, FileMode.Append)); //Writes a region of a byte array to the current stream.
            bWrite.Write(clientData, 4 + fileNameLen, receivedBytesLen - 4 - fileNameLen);
            Console.WriteLine("File: {0} received & saved at path: {1}", fileName, storagePath);
            bWrite.Close();
        }

        private void DownloadServer()
        {
            byte[] clientData = new byte[1024*5000];
            int receivedBytesLen = clientSocket.Receive(clientData);
            string fileName = Encoding.ASCII.GetString(clientData, 0,receivedBytesLen);
            DirectoryInfo directory = new DirectoryInfo(storagePath);
            FileInfo[] files = directory.GetFiles();
            byte isFound;
            bool flag = false;
            foreach (FileInfo file in files)
            {
                if (file.Name == fileName)
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                isFound = 1;
                byte[] fileData=File.ReadAllBytes(storagePath+fileName);
                byte[] dataToSend = new byte[1 + fileData.Length];
                dataToSend[0] = isFound;
                fileData.CopyTo(dataToSend, 1);
                clientSocket.Send(dataToSend);
                Console.WriteLine("File : {0} has been sent to {1}", fileName, clientSocket.RemoteEndPoint);
            }
            else
            {
                isFound = 0;
                byte[] dataToSend = new byte[1];
                dataToSend[0] = isFound;
                clientSocket.Send(dataToSend);
            }
        }

        private void ListServer()
        {
            DirectoryInfo directory = new DirectoryInfo(storagePath);
            FileInfo[] files = directory.GetFiles();
            int fileNum = files.Length;
            int countFileByteLen = 0;
            foreach(FileInfo file in files)
            {
                byte[] fileNameInBytes = Encoding.ASCII.GetBytes(file.Name);
                countFileByteLen += fileNameInBytes.Length;
            }
            byte[] dataToSend = new byte[4 + fileNum * 4 + countFileByteLen];
            byte[] fileNumBytes = BitConverter.GetBytes(fileNum);
            fileNumBytes.CopyTo(dataToSend, 0);
            countFileByteLen = 4;//
            foreach (FileInfo file in files)
            {
                byte[] fileNameInBytes = Encoding.ASCII.GetBytes(file.Name);
                int fileNameLen = fileNameInBytes.Length;
                byte[] fileNameLenBytes = BitConverter.GetBytes(fileNameLen);
                fileNameLenBytes.CopyTo(dataToSend, countFileByteLen);
                countFileByteLen += 4;
                fileNameInBytes.CopyTo(dataToSend, countFileByteLen);
                countFileByteLen += fileNameInBytes.Length;
            }
            clientSocket.Send(dataToSend);
        }

        private void SearchServer()
        {
            byte[] clientData = new byte[1024 * 5000];
            int receivedBytesLen = clientSocket.Receive(clientData);
            string fileName = Encoding.ASCII.GetString(clientData, 0, receivedBytesLen);
            DirectoryInfo directory = new DirectoryInfo(storagePath);
            FileInfo[] files = directory.GetFiles();
            byte[] isFound=new byte[1];
            bool flag = false;
            foreach (FileInfo file in files)
            {
                if (file.Name == fileName)
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
                isFound[0] = 1;
            else isFound[0] = 0;
            clientSocket.Send(isFound);
        }
    }
}
