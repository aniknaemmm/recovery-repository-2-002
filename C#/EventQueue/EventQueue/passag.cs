using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace EventQueue
{
    class Passenger
    {
        public static int count = 0;
        public station from, to;
        public Train myTrain;
        public string name;
        public uint wait;

        public Passenger(string name, uint time, station from, station to)
        {
            this.name = name;
            wait = time;
            myTrain = null;
            this.from = from;
            this.to = to;
            count++;

        }
        public uint go(uint time)
        {
            wait = time - wait;
               return wait;
        }


    }
}
