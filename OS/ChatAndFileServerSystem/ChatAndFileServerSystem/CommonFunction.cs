using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;
using System.Net;
using System.Net.Sockets;

namespace ChatAndFileServerSystem
{
    class CommonFunction
    {
        static public TcpListener StartTCPServer(int port)
        {
            TcpListener serverListener = default (TcpListener);
            try
            {
                serverListener = new TcpListener(IPAddress.Any, port);
                return serverListener;
            }
            catch (Exception ex)
            {
                Console.WriteLine("Could not start server");
                Console.WriteLine(ex.ToString());
                Console.Read();
                Environment.Exit(0);
            }
            return serverListener;
        }

        static public TcpClient StartTCPClient(string ipAddress, int port)
        {
            TcpClient clientSocket = new TcpClient();
            try
            {
                clientSocket.Connect(ipAddress, port);
                return clientSocket;
            }
            catch(Exception ex)
            {
                Console.WriteLine("Could not connect to server");
                Console.WriteLine(ex.ToString());
                Console.Read();
                Environment.Exit(0);
            }
            return clientSocket;
        }

        static public void Broadcast(string msg, Hashtable clientsList)
        {
            TcpClient broadcastSocket;
            NetworkStream broadcastStream;
            byte[] broadcastBytes = null;
            foreach (DictionaryEntry item in clientsList)
            {
                broadcastSocket = (TcpClient)item.Value;
                broadcastStream = broadcastSocket.GetStream();
                broadcastBytes = System.Text.Encoding.ASCII.GetBytes(msg + "$");
                broadcastStream.Write(broadcastBytes, 0, broadcastBytes.Length);
                broadcastStream.Flush();
            }
        }

        static public bool SendMessage(string msg, string senderName, string receiverName,Hashtable clientsList)
        {
            if (clientsList.Contains(receiverName) == false)
                return false;
            TcpClient receiverSocket = clientsList[receiverName] as TcpClient;
            string msgToSend = senderName + " says : " + msg+ "$";
            byte[] bytesToSend = Encoding.ASCII.GetBytes(msgToSend);
            NetworkStream messageStream = receiverSocket.GetStream();
            messageStream.Write(bytesToSend, 0, bytesToSend.Length);
            messageStream.Flush();
            Console.WriteLine(senderName + " said to " + receiverName + " : " + msg);
            return true;
        }

        static public void ServerResponse(string msg, TcpClient clientSocket)
        {
            byte[] bytesToSend = Encoding.ASCII.GetBytes(msg + "$");
            NetworkStream messageStream = clientSocket.GetStream();
            messageStream.Write(bytesToSend, 0, bytesToSend.Length);
            messageStream.Flush();
        }

    }
}
