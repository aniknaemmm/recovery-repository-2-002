using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace eventd
{//wtf need public or accessibility less
    class deal
    {
        public Contractor contactor;
        public int money;
        public bool isFair;
        public deal(Contractor cont, int money)
        {
            Random temp = new Random(DateTime.Now.Millisecond);
            isFair = temp.Next(1, 10) == 1 ? false : true;
            this.money = money;
            this.contactor = cont;
        }


    }
}
