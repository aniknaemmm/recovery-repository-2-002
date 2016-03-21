using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace eventd
{
    class audit
    {
        string title;
        int biiigz = 0;
        bool seel;
        public audit()
        {
        }
        public audit(string title, int monyd, int monye, bool seel)
        {
            this.title = title;
            this.seel = seel;
            if (monyd > monye) { biiigz = monyd; }
            else { biiigz = monye; }
        }

        public void doaudit(string title, int monyd, int monye, bool seel)
        {
            if (biiigz < monyd)
            {
                biiigz = monyd;
                Console.WriteLine("audirovanie : client {0} big bid {1} sell={2} , by={3}",title,biiigz,seel,seel);
            }
            else if (biiigz < monye)
            {
                biiigz = monye;
                Console.WriteLine("audirovanie : client {0} big bid {1} sell={2} , by={3}", title, biiigz, seel, seel);
            }

            
        }

    }
}
