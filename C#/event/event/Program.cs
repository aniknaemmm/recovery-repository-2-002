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
            exchange temp = new exchange();
            protocol hendl1 = new protocol();
            audit hend2 = new audit();
            temp.onPattern += hendl1.prot;
            temp.onPattern += hend2.doaudit;
            temp.onPattern += temp.deal;
            temp.bid("123",7,1,true);
            temp.bid("123", 1, 3, false);
            temp.bid("123", 5, 10, false);
            temp.bid("123", 3, 3, true);
            temp.bid("123", 9, 2, true);
            Console.ReadLine();
        }
    }
}
