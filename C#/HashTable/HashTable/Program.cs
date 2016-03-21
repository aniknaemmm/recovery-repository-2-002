using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HashTable
{
    class Program
    {
        static void Main(string[] args)
        {
            Hashtable<int, string> hash = new Hashtable<int, string>(10);
            hash[1] = "mama";
            hash[2] = "mila";
            hash[3] = "ramu";
            hash.print();
            Console.ReadLine();
        }
    }
}
