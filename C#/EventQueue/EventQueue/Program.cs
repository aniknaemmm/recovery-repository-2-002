using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EventQueue
{


    class Program
    {
        public static station[] stations = new station[5] 
        { 
            new station("raz", 4),
            new station("dvaz", 5), 
            new station("triz", 3),
            new station("4tiriz", 4), 
            new station("5riz", 2) 
        };

        public static Train[] trains = new Train[5] 
        { 
          new Train(),
          new Train(),
          new Train(), 
          new Train(), 
          new Train() 
        
        };

        public static uint[] intervalstation = new uint[5] { 30, 50, 20, 30, 10 };
        public static EventedQueue queue = new EventedQueue();

        static void Main(string[] args)
        {
            if (File.Exists("file.csv"))
            {
                File.Delete("file.csv");
            }
            if (File.Exists("fileWait.csv"))
            {
                File.Delete("fileWait.csv");
            }
            if (File.Exists("peoplestation.csv"))
            {
                File.Delete("peoplestation.csv");
            }
            queue.AddEvent(1, stations[0].AddPassg);
            queue.AddEvent(30, stations[1].AddPassg);
            queue.AddEvent(80, stations[2].AddPassg);
            queue.AddEvent(100, stations[3].AddPassg);
            queue.AddEvent(110, stations[4].AddPassg);
            queue.AddEvent(30, trains[0].arrival);
            queue.AddEvent(80, trains[1].arrival);
            queue.AddEvent(100, trains[2].arrival);
            queue.AddEvent(130, trains[3].arrival);
            queue.AddEvent(140, trains[4].arrival);


            uint time = 0;

            while (time < 1000)
            {
                var events = queue.PopEvent(out time);
                events(time);
                string buf = "";
                foreach (var x in Program.stations)
                {
                    buf += x.QueuePassg.Count.ToString();
                    buf += ";";

                }
                File.AppendAllText("peoplestation.csv", buf + Environment.NewLine, Encoding.UTF8);
            }



           /* using (StreamReader file = new StreamReader("failWait.csv"))
            {
                int tt = 0;
                int count = 0;
                int temp;
                while (!file.EndOfStream)
                {
                     temp = Int32.Parse(file.ReadLine());
                    tt += temp;
                    count++;

                    Console.WriteLine(temp);
                }
                Console.WriteLine(tt/count+"312312312fdfsfsd");
            }
            */





            Console.ReadKey();
        }
    }
}
