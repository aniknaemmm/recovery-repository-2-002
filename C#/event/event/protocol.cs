using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace eventd
{
    class protocol
    {
        List<protocol> temp = new List<protocol>();
        string title;
        int monyd;
        int monye;
        bool seel;
        int count=0;
        public protocol() 
        {

        }
        public protocol(string title, int monyd, int monye, bool seel, int count)
        {
            this.title = title;
            this.monyd = monyd;
            this.monye = monye;
            this.seel = seel;
            this.count = count;
        }
        public void prot(string title, int monyd, int monye, bool seel)
        {
            count += 1;
            temp.Add(new protocol(title, monyd, monye, seel,count));
            Console.WriteLine("protokol numb {0}",count);
        }
    }
}
