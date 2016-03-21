using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EventQueue
{
    class Train
    {
        public const int MAX_SIZE = 100;
        public List<Passenger> passenger;
        public int numberPassg;
        public int currentStation;

        public Train()
            : this(0)
        {

        }
        public Train(int currentStation)
        {
            passenger = new List<Passenger>();
            this.currentStation = currentStation;
        }

        //выгрузить
        public void arrival(uint time)
        {

            Program.stations[currentStation].Came(this, time);
            Program.queue.AddEvent(time + 5, departure);
        }
        //погрузить
        public void departure(uint time)
        {
            Program.stations[currentStation].Go(this, time);
            Program.queue.AddEvent(time + Program.intervalstation[currentStation], arrival);

            if (currentStation + 1 < Program.stations.Length)
            {
                ++currentStation;
            }
            else
            {
                currentStation = 0;
            }

            File.AppendAllText("file.csv", (numberPassg + ";" + time.ToString() + ";" + ";" + Environment.NewLine), Encoding.UTF8);

        }



    }
}
