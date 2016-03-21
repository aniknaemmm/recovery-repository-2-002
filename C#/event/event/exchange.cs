using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace eventd
{
    public delegate void pattern(string title , int monyd, int monye , bool seel) ;
    class exchange
    {
        public exchange() 
        {

        }

        public event pattern onPattern;
        
        public void deal(string title , int monyd, int monye , bool seel) 
        {
            Console.WriteLine(title+"-"+" usd="+monyd+""+" eur="+monye+" by="+seel);
        }

        public void bid(string title, int monyd, int monye, bool seel)
        {
            onPattern(title, monyd, monye, seel) ;
        }



    }
}
