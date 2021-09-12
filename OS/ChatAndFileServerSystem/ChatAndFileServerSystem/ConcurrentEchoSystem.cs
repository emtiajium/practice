using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ChatAndFileServerSystem
{
    class ConcurrentEchoSystem
    {
        static public void Start()
        {
            Console.Clear();
            Console.WriteLine("Choose one of the following services : " + Environment.NewLine);
            Console.WriteLine("1. Start a Concurrent Echo Server");
            Console.WriteLine("2. Connect to a Concurrent Echo Server" + Environment.NewLine);
            string input;
            int chosenService;
            while (true)
            {
                Console.Write("Option : ");
                input = Console.ReadLine();
                chosenService = Convert.ToInt32(input);
                if (chosenService != 1 && chosenService != 2)
                    Console.WriteLine("Invalid Input Try Again");
                else break;
            }
            if (chosenService == 1)
            {
                ConcurrentEchoServer echoServer = new ConcurrentEchoServer();
                echoServer.Start();
            }
            else
            {
                EchoClient echoClient = new EchoClient();
                echoClient.Start();
            }
        }
    }
}
