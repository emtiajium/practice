using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net;
using System.Net.Sockets;

namespace ChatAndFileServerSystem
{
    class EchoClient
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
            clientStream = clientSocket.GetStream();
            EnterUserName();
            SendMessage();
        }

        private void EnterUserName()
        {
            Console.Write("Enter a user name : ");
            userName = Console.ReadLine();
            byte[] sendData = Encoding.ASCII.GetBytes(userName + "$");
            clientStream.Write(sendData, 0, sendData.Length);
            clientStream.Flush();
        }

        private void SendMessage()
        {
            while (true)
            {
                string outData = Console.ReadLine();
                NetworkStream serverStream = clientSocket.GetStream();
                byte[] outStream = new byte[10025];
                outStream = System.Text.Encoding.ASCII.GetBytes(outData + "$");
                serverStream.Write(outStream, 0, outStream.Length);
                serverStream.Flush();
                if (outData == "End Of Session")
                {
                    Console.Read();
                    Environment.Exit(0);
                }

                byte[] inStream = new byte[10025];
                serverStream.Read(inStream, 0, (int)clientSocket.ReceiveBufferSize);
                string inData = Encoding.ASCII.GetString(inStream);
                inData = inData.Substring(0, inData.IndexOf("$"));
                Console.WriteLine(inData);
            }
        }
    }
}
