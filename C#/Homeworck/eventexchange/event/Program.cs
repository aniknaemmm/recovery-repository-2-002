using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace eventd
{
    
    class Program
    {
        static void Main(string[] args)
        {
            Random r= new Random(DateTime.Now.Millisecond);
            exchange exchange= new exchange();
            Contractor cont;
            for (int i = 0; i < 1000; i++) 
            {
                cont = Contractor.Contactors("contactor" + i.ToString(), r.Next(0, 10));
                cont.makeDeal(exchange,r.Next(0,20000));
            }
            for (int i = 0; i < 1000; i++)
            {
                cont = Contractor.Contactors("contactor" + i.ToString(), r.Next(0, 10));
                cont.makeDeal(exchange, r.Next(0, 20000));
            }
            exchange.statistic();
            
                Console.ReadLine();
        }
    }
}
