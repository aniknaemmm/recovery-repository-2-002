using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace eventd
{
    class Contractor
    {
        delegate Contractor checkName(string name);
        /*
         * Contractordeals : history list deal
         */
        private string nameContactor;
        private int raitingContactor;
        private List<deal> ContractorDeals;

        //list all Contractor
        private static List<Contractor> listContactors = new List<Contractor>();
        private Contractor(string name, int raiting)
        {
            this.nameContactor = name;
            this.raitingContactor = raiting;
            this.ContractorDeals = new List<deal>();
        }

        public static Contractor Contactors(string nameContactor, int raitingContactor)
        {
            /*
             *function chek name Contractor 
             */
            checkName check = x =>
            {
                foreach (var ContractorsName in listContactors)
                {
                    if (ContractorsName.nameContactor == x) return ContractorsName;
                }
                return null;
            };

            //adding new contactor
            Contractor temp = check(nameContactor);
            if (listContactors.Count == 0 || temp == null)
            {
                temp = new Contractor(nameContactor, raitingContactor);
                listContactors.Add(temp);
            }

            return temp;
        }

        public int Raiting
        {
            get { return raitingContactor; }
        }

        public string Name
        {
            get { return nameContactor; }
        }

        public void makeDeal(exchange exchange, int moneyd)
        {
            reRatingCont();
            deal deal = new deal(this, moneyd);
            ContractorDeals.Add(deal);
            exchange.bid(deal);
        }
        private void reRatingCont()
        {
            int i = 0;
            if (ContractorDeals.Count > 5)
            {
                foreach (var x in ContractorDeals)
                {
                    if (x.isFair) i++;
                } this.raitingContactor = (ContractorDeals.Count / i) * 10;
            }


        }

    }
}
