using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net;
using System.Net.Sockets;
using System.Threading;

namespace ChatAndFileServerSystem
{
    class ConcurrentEchoServer
    {
        TcpListener serverSocket;
        TcpClient clientSocket;
        string clientName;

        public void Start()
        {
            Console.Clear();
            Console.Write("Enter port : ");
            string input = Console.ReadLine();
            int port = Convert.ToInt32(input);
            this.serverSocket = CommonFunction.StartTCPServer(port);
            serverSocket.Start();
            Console.WriteLine("Concurrent Echo Server Started");
            AcceptConnections();
        }

        public void AcceptConnections()
        {
            while (true)
            {
                clientSocket = serverSocket.AcceptTcpClient();

                byte[] bytesFrom = new byte[8192];

                Console.WriteLine("New User Connected");

                NetworkStream networkStream = clientSocket.GetStream();
                networkStream.Read(bytesFrom, 0, (int)clientSocket.ReceiveBufferSize);
                clientName = System.Text.Encoding.ASCII.GetString(bytesFrom);
                clientName = clientName.Substring(0, clientName.IndexOf("$"));
                Console.WriteLine(clientName + " Joined Echo Room");

                HandleEchoClient client = new HandleEchoClient();
                client.StartClient(clientSocket, clientName);
            }
        }
    }

    class HandleEchoClient
    {
        TcpClient clientSocket;
        string userName;

        public void StartClient(TcpClient inClientSocket, string clientName)
        {
            this.clientSocket = inClientSocket;
            this.userName = clientName;
            Thread clientThread = new Thread(DoEcho);
            clientThread.Start();
        }

        private void DoEcho()
        {
            while (true)
            {
                try
                {
                    NetworkStream networkStream = clientSocket.GetStream();
                    byte[] inData = new byte[8192];
                    networkStream.Read(inData, 0, (int)clientSocket.ReceiveBufferSize);
                    string data = Encoding.ASCII.GetString(inData);
                    data = data.Substring(0, data.IndexOf("$"));
                    Console.WriteLine(userName + " Said : " + data);
                    if (data == "End Of Session")
                        break;
                    byte[] outData = new byte[8129];
                    outData = Encoding.ASCII.GetBytes("Server Responded : " + data + "$");
                    networkStream.Write(outData, 0, outData.Length);
                    networkStream.Flush();
                }
                catch (Exception ex)
                {
                    break;
                }
            }
            Console.WriteLine(userName + " disconnected");
        }
    }
}
