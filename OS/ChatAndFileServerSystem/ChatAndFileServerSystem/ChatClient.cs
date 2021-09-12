using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net;
using System.Net.Sockets;
using System.Threading;

namespace ChatAndFileServerSystem
{
    class ChatClient
    {
        TcpClient clientSocket;
        string userName;
        NetworkStream clientStream;
        public void Start()
        {
            Console.Clear();
            Console.Write("Enter IP Address of Server : ");
            string ipAddress = Console.ReadLine();
            Console.Write("Enter port to connect to : ");
            string input = Console.ReadLine();
            int port = Convert.ToInt32(input);
            clientSocket = CommonFunction.StartTCPClient(ipAddress, port);
            Console.WriteLine("Connected to Server");
            clientStream=clientSocket.GetStream();
            EnterUserName();
            byte[] receiveData = new byte[8192];
            clientStream.Read(receiveData, 0, 8192);
            string serverResponse = Encoding.ASCII.GetString(receiveData);
            serverResponse = serverResponse.Substring(0, serverResponse.IndexOf("$"));
            Console.WriteLine(serverResponse);
            sendData qwe = new sendData();
            qwe.StartClient(clientSocket);   
            receiveData asd = new receiveData();
            asd.StartClient(clientSocket);
        }

        private void EnterUserName()
        {
            Console.Write("Enter a user name : ");
            userName = Console.ReadLine();
            byte[] sendData = Encoding.ASCII.GetBytes(userName+"$");
            clientStream.Write(sendData, 0, sendData.Length);
            clientStream.Flush();
        }

        class receiveData
        {
            TcpClient clientSocket;

            public void StartClient(TcpClient inClientSocket)
            {
                this.clientSocket = inClientSocket;
                Thread ctThread = new Thread(getMessage);
                ctThread.Start();
            }
            private void getMessage()
            {
                while (true)
                {
                    try
                    {
                        NetworkStream serverStream = clientSocket.GetStream();
                        byte[] inStream = new byte[10025];
                        int buffSize = clientSocket.ReceiveBufferSize;
                        serverStream.Read(inStream, 0, 8192);
                        string returnData = System.Text.Encoding.ASCII.GetString(inStream);
                        returnData = returnData.Substring(0, returnData.IndexOf("$"));
                        Console.WriteLine(returnData);
                    }
                    catch (Exception ex)
                    {
                        Console.WriteLine("Server Disconnected");
                        break;
                    }
                }
            }
        }

        class sendData
        {
            TcpClient clientSocket;

            public void StartClient(TcpClient inClientSocket)
            {
                this.clientSocket = inClientSocket;
                Thread ctThread = new Thread(sendMessage);
                ctThread.Start();
            }
            private void sendMessage()
            {
                while (true)
                {
                    string outData = Console.ReadLine();
                    //outData += "$";
                    NetworkStream serverStream = clientSocket.GetStream();
                    byte[] outStream = new byte[10025];
                    outStream = System.Text.Encoding.ASCII.GetBytes(outData+"$");
                    //int buffSize = clientSocket.ReceiveBufferSize;
                    serverStream.Write(outStream, 0, outStream.Length);
                    serverStream.Flush();
                    if (outData == "End Of Session")
                    {
                        Console.Read();
                        Environment.Exit(0);
                    }
                }
            }
        }
    }
}
