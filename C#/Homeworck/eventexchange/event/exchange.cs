using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace eventd
{

    // public delegate void pattern(string title, int monyd, int monye, bool seel);

    class exchange
    {
        public delegate void bidDeal(deal deals);
        public readonly int sumAuditLimits;
        //max raiting from audit
        public readonly int maxAuditRatingContactor;
        private audit auditor;
        private const double auditorMonyP = 0.02;
        public protocol protocol;
        private event bidDeal dealevent = (s) => { };

        Random random = new Random(DateTime.Now.Millisecond);

        /*
         * default value sumAuditLimits = 1000 and  maxRatingContactor = 5
         * the maximum rating 10 
         */
        private const int limit = 1000, raiting = 5;
        public exchange(int sumAuditLimits = limit, int maxRatingContactor = raiting)
        {
            this.sumAuditLimits = sumAuditLimits;
            this.maxAuditRatingContactor = maxRatingContactor;
            auditor = new audit("auditor");
            protocol = new protocol();
            dealevent += protocol.addProtocol;
        }



        public void bid(deal deals)
        {

            bool auditRaiting = deals.contactor.Raiting > maxAuditRatingContactor ? (random.Next(1, 10) == 1 ? true : false) : true;
            bool auditMoneyd = deals.money > this.sumAuditLimits ? (random.Next(1, 10) == 1 ? true : false) : true;
            if (auditRaiting && auditMoneyd)
            {
                auditor.money += (int)(deals.money * auditorMonyP);
                deals.money -= (int)(deals.money * auditorMonyP);
                auditor.doaudit(deals);
            }

            dealevent(deals);
        }
        public void statistic()
        {
            Console.WriteLine(auditor.money);
            int sumIsFair = 0;
            int sumIsNFair = 0;
            int summAllDeal = 0;
            int procFairDeal = 0;
            int procNFairDeal = 0;

            foreach (var x in protocol.list)
            {
                summAllDeal += x.monyd;
                if (x.frai)
                {
                    sumIsFair += x.monyd;
                    procFairDeal++;
                }
                else
                {
                    sumIsNFair += x.monyd;
                    procNFairDeal++;
                }
            }

            procFairDeal = (100 * procFairDeal) / protocol.list.Count;
            procNFairDeal = 100 - procFairDeal;
            Console.WriteLine("summ {0} \nfair{1} \n nfair{2}\n proc fiar{3} proc nfiar{4}",summAllDeal,sumIsFair,sumIsNFair,procFairDeal,procNFairDeal);
        }



    }
}
