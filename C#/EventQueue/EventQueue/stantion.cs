using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
namespace EventQueue
{
    class station
    {
        public Queue<Passenger> QueuePassg;
        string name;
        uint passArrival;

        public station(string nameStantion, uint interval)
        {
            QueuePassg = new Queue<Passenger>();
            this.passArrival = interval;
            name = nameStantion;
        }
        public void AddPassg(uint time)
        {
            Random random = new Random(DateTime.Now.Millisecond);
            station toStation;

            if (Program.stations.Length == 1)
            {
                throw Exceptions("one station");
            }
            if (this == Program.stations[Program.stations.Length - 1])
            {
                toStation = Program.stations[random.Next(0, Program.stations.Length - 1)];
            }
            else
            {
                int pos = Array.FindIndex(Program.stations, (x) => x == this);
                toStation = Program.stations[random.Next(pos, Program.stations.Length - 1)];
            }

            QueuePassg.Enqueue(new Passenger("Passgener" + Passenger.count.ToString(), time, this, toStation));
            Program.queue.AddEvent(time + passArrival, AddPassg);
        }


        public void Came(Train train, uint time)
        {
            if (train.passenger.Count != 0)
            {
                train.passenger.RemoveAll(pas =>
                    {
                        if (pas.to == this)
                        {
                            train.numberPassg--;
                            return true;
                        }
                        else
                            return false;

                    });
            }

        }
        public void Go(Train train, uint time)
        {
            List<uint> median = new List<uint>();

            while (train.numberPassg < Train.MAX_SIZE && QueuePassg.Count != 0)
            {
                Passenger passg = QueuePassg.Dequeue();
                train.numberPassg++;
                median.Add(passg.go(time));
                passg.myTrain = train;
                train.passenger.Add(passg);
            }

            uint temp = 0;
            foreach (var xar in median)
            {
                temp += xar;
            }
            double result = (double)temp / median.Count;
            median.Sort();
            uint medianaa = median.ElementAt(median.Count / 2);
            File.AppendAllText("wait.csv", result + ";"+medianaa+";"+Environment.NewLine, Encoding.UTF8);

        }


        private Exception Exceptions(string p)
        {
            throw new ArgumentException();
        }

    }
}
