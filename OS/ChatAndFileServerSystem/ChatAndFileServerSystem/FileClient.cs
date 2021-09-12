using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net;
using System.Net.Sockets;
using System.IO;

namespace ChatAndFileServerSystem
{
    class FileClient
    {
        Socket clientSocket;
        
        public void Start()
        {
            Console.Clear();
            Console.Write("Enter IP Address of Server : ");
            string ip = Console.ReadLine();
            Console.Write("Enter port to connect to : ");
            string input = Console.ReadLine();
            int port = Convert.ToInt32(input);

            IPAddress[] ipAddress = Dns.GetHostAddresses(ip);
            IPEndPoint ipEnd = new IPEndPoint(ipAddress[0], port);

            clientSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.IP);
            clientSocket.Connect(ipEnd);

            Console.WriteLine("Connected to Server");
            Console.ReadLine();

            while (true)
            {
                Console.Clear();
                Console.WriteLine("Choose one of the following services : " + Environment.NewLine);
                Console.WriteLine("1. Upload a file");
                Console.WriteLine("2. Download a file");
                Console.WriteLine("3. View list of all files");
                Console.WriteLine("4. Search a file");
                Console.WriteLine("5. Exit" + Environment.NewLine);
                int chosenService;
                while(true)
                {
                    Console.Write("Option : ");
                    input = Console.ReadLine();
                    chosenService = Convert.ToInt32(input);
                    if (chosenService > 5 && chosenService < 1)
                        Console.WriteLine("Invalid Input Try Again");
                    else break;
                }
                byte[] sendData = BitConverter.GetBytes(chosenService);
                clientSocket.Send(sendData);
                if (chosenService == 1)
                    UploadClient();
                else if (chosenService == 2)
                    DownloadClient();
                else if (chosenService == 3)
                    ListClient();
                else if (chosenService == 4)
                    SearchClient();
                else
                    break;
            }
        }

        private void UploadClient()
        {
            Console.Write("Enter a file name : ");
            string fileName = Console.ReadLine();
            Console.Write("Enter the path of the file : ");
            string filePath = Console.ReadLine();

            byte[] fileNameByte = Encoding.ASCII.GetBytes(fileName);
            byte[] fileData = File.ReadAllBytes(filePath + fileName);
            byte[] fileNameLen = BitConverter.GetBytes(fileNameByte.Length);

            byte[] clientData=new byte[4+fileNameByte.Length+fileData.Length];

            fileNameLen.CopyTo(clientData,0);
            fileNameByte.CopyTo(clientData,4);
            fileData.CopyTo(clientData,4+fileNameByte.Length);

            clientSocket.Send(clientData);
            Console.WriteLine("File : {0} has been sent.", fileName);
            Console.ReadLine();
        }

        private void DownloadClient()
        {
            Console.Write("Enter a file name : ");
            string fileName = Console.ReadLine();
            Console.Write("Enter the path to store the file : ");
            string filePath = Console.ReadLine();

            byte[] fileNameByte = Encoding.ASCII.GetBytes(fileName);
            clientSocket.Send(fileNameByte);

            byte[] receiveData = new byte[1024 * 5000];
            int receivedBytesLen = clientSocket.Receive(receiveData);

            if (receiveData[0] == 0)
                Console.WriteLine("File Not Found");
            else
            {
                BinaryWriter bWrite = new BinaryWriter(File.Open(filePath + fileName, FileMode.Append));
                bWrite.Write(receiveData, 1, receivedBytesLen - 1);
                Console.WriteLine("File {0} sucessfully received and stored at {1}", fileName, filePath);
                bWrite.Close();
            }
            Console.ReadLine();
        }

        private void ListClient()
        {
            Console.Clear();
            Console.WriteLine("The Server Contains the following files" + Environment.NewLine);
            byte[] receiveData = new byte[1024 * 5000];
            clientSocket.Receive(receiveData);

            int numOfFiles = BitConverter.ToInt32(receiveData, 0);
            int currentOffset = 4;

            for (int i = 1; i <= numOfFiles; i++)
            {
                int fileNameLen = BitConverter.ToInt32(receiveData, currentOffset);
                currentOffset += 4;
                string fileName = Encoding.ASCII.GetString(receiveData, currentOffset, fileNameLen);
                Console.WriteLine("{0}. {1}", i, fileName);
                currentOffset += fileNameLen;
            }
            Console.ReadLine();
        }

        private void SearchClient()
        {
            Console.Write("Enter a file name : ");
            string fileName = Console.ReadLine();

            byte[] fileNameByte = Encoding.ASCII.GetBytes(fileName);
            clientSocket.Send(fileNameByte);

            byte[] responseByte = new byte[10];
            clientSocket.Receive(responseByte);

            if (responseByte[0] == 1)
                Console.WriteLine("File Found In Server");
            else
                Console.WriteLine("File NOT Found In Server");
            Console.ReadLine();
        }
    }
}
