using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace eventd
{
    class audit
    {
        string auditor;
        public int money = 0;
        Random rand;
        public audit(string auditor)
        {
            this.auditor = auditor;
            rand = new Random(DateTime.Now.Millisecond);
        }


        //true or false
        public bool doaudit(deal deal)
        {
            if (rand.Next(1, 100) < 20)
            {
                deal.isFair = !deal.isFair;
            }
            return deal.isFair;

        }

    }
}
