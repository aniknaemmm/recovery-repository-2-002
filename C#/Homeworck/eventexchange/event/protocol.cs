using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace eventd
{
    class protocol
    {
        public List<protocol> list;
        public string name;
        public int monyd;
        public bool frai;
        public int count;
   
        public protocol()
        {
           list = new List<protocol>();
            count = 0;
        }
        public protocol(string name, int mony, bool frai,int count) 
        {
            this.name = name;
            this.monyd = mony;
            this.frai = frai;
            this.count = count;
        }
        public void addProtocol(deal deals)
        {
            count += 1;
            list.Add(new protocol(deals.contactor.Name,deals.money,deals.isFair,count));
            if(true)Console.WriteLine("protokol namme {0}  money{1}  fair{2}  count{3}", deals.contactor.Name, deals.money, deals.isFair, count);
        }
    }
}
