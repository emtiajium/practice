using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;
using System.Net;
using System.Net.Sockets;
using System.Threading;

namespace ChatAndFileServerSystem
{
    class ChatServer
    {
        TcpListener serverSocket;
        TcpClient clientSocket;

        public static Hashtable clientsList = new Hashtable();

        public void Start()
        {
            Console.Clear();
            Console.Write("Enter port : ");
            string input = Console.ReadLine();
            int port = Convert.ToInt32(input);
            this.serverSocket =  CommonFunction.StartTCPServer(port);
            serverSocket.Start();
            Console.WriteLine("Chat Server Started");
            AcceptConnections();
        }

        public void AcceptConnections()
        {
            while(true)
            {
                clientSocket=serverSocket.AcceptTcpClient();

                byte[] bytesFrom = new byte[8192];
                string clientName = null;

                Console.WriteLine("New User Connected");

                NetworkStream networkStream = clientSocket.GetStream();
                networkStream.Read(bytesFrom,0,8192);
                clientName=System.Text.Encoding.ASCII.GetString(bytesFrom);
                //dataFromClient=dataFromClient.Substring(0,dataFromClient.IndexOf("$"));
                clientName = clientName.Substring(0, clientName.IndexOf("$"));

                clientsList.Add(clientName, clientSocket);

                Console.WriteLine(clientName + " Joined Chat Room");
                CommonFunction.Broadcast(clientName + " Joined",clientsList);

                string currentUserList = "Currently connected to the server are :";

                foreach (DictionaryEntry item in clientsList)
                {
                    currentUserList += " " + item.Key as string;
                }

                CommonFunction.ServerResponse(currentUserList,clientSocket);

                HandleClient client = new HandleClient();
                client.StartClient(clientSocket, clientName, clientsList);
            }
        }
    }

    class HandleClient
    {
        TcpClient clientSocket;
        string userName;
        Hashtable clientsList;

        public void StartClient(TcpClient inClientSocket, string clientName, Hashtable clientList)
        {
            this.clientSocket = inClientSocket;
            this.userName = clientName;
            this.clientsList = clientList;
            Thread clientThread = new Thread(DoChat);
            clientThread.Start();
            //this.clientSocket.Close();
        }

        private void DoChat()
        {
            byte[] bytesFrom = new byte[8192];
            string receiverName = null;
            string dataFromClient = null;
            string message = null;           

            while (true)
            {
                try
                {
                    NetworkStream networkStream = clientSocket.GetStream();
                    networkStream.Read(bytesFrom, 0, 8192);
                    dataFromClient = Encoding.ASCII.GetString(bytesFrom, 0, bytesFrom.Length);
                    receiverName = dataFromClient.Substring(0, dataFromClient.IndexOf(":"));
                    message = dataFromClient.Substring(dataFromClient.IndexOf(":") + 1,dataFromClient.IndexOf("$")-dataFromClient.IndexOf(":")-1);
                    //Console.WriteLine(message);
                    if (dataFromClient == "End Of Session")
                        break;
                    if (CommonFunction.SendMessage(message, userName, receiverName, clientsList) == false)
                        CommonFunction.ServerResponse("No such user in system", clientSocket);
                }
                catch (Exception ex)
                {
                    //Console.WriteLine(ex.ToString());
                    break;
                }
            }
            Console.WriteLine(this.userName + " has disconnected");
            clientsList.Remove(this.userName);
            CommonFunction.Broadcast(this.userName + " has left the room", clientsList);
        }
    }
}
