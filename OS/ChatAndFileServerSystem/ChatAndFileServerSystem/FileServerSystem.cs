using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ChatAndFileServerSystem
{
    class FileServerSystem
    {
        static public void Start()
        {
            Console.Clear();
            Console.WriteLine("Choose one of the following services : " + Environment.NewLine);
            Console.WriteLine("1. Start a File Server");
            Console.WriteLine("2. Connect to a File Server" + Environment.NewLine);
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
                FileServer fileServer = new FileServer();
                fileServer.Start();
            }
            else
            {
                FileClient fileClient = new FileClient();
                fileClient.Start();
            }
        }
    }
}
