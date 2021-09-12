using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ChatAndFileServerSystem
{
    class StartUp
    {
        static void Main(string[] args)
        {
            int chosenService = ChooseService();
            if (chosenService == 2)
                ChatSystem.Start();
            else if (chosenService == 3)
                FileServerSystem.Start();
            else if (chosenService == 4)
                IterativeEchoSystem.Start();
            else if (chosenService == 5)
                ConcurrentEchoSystem.Start();
        }

        static public int ChooseService()
        {
            Console.WriteLine("Choose one of the following services : " + Environment.NewLine);
            Console.WriteLine("1. Echo Server");
            Console.WriteLine("2. Chat Server");
            Console.WriteLine("3. File Server");
            Console.WriteLine("4. Exit" + Environment.NewLine);
            while(true)
            {
                Console.Write("Option : ");
                string input = Console.ReadLine();
                int chosenService = Convert.ToInt32(input);
                if (chosenService == 2 || chosenService == 3)
                    return chosenService;
                else if (chosenService == 1)
                {
                    Console.Clear();
                    Console.WriteLine("Choose one of the followin services : " + Environment.NewLine);
                    Console.WriteLine("1. Iterative Server");
                    Console.WriteLine("2. Concurrent Server");
                    Console.WriteLine("3. Exit" + Environment.NewLine);
                    while (true)
                    {
                        Console.Write("Option : ");
                        input = Console.ReadLine();
                        chosenService = Convert.ToInt32(input);
                        if (chosenService == 1 || chosenService == 2)
                            return chosenService + 3;
                        if (chosenService == 3)
                        {
                            chosenService = 4;
                            break;
                        }
                        Console.WriteLine("Invalid Input. Please Try Again.");
                    }
                }
                if (chosenService == 4)
                    Environment.Exit(0);
                else
                    Console.WriteLine("Invalid Input. Please Try Again.");
            }
        }
    }
}
