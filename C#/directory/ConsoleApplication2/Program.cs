using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication2
{
    class Program
    {
        static void Main(string[] args)
        {
            Directrory temp = new Directrory();
            //temp.GetCurrentDirectory();
           // temp.GetDirectories();
            temp.search(@"C:\Users\st","loxpox");
        }
    }
}
