using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;
using System.Xml;

namespace Serializable
{
    [Serializable()]
    public class Pupils
    {
      [XmlIgnore]
        public int year;
        public string name;


        public Pupils()
        {
            year = 0;
            name = "vasia";
        }

        public Pupils(int year, string name)
        {
            this.year = year;
            this.name = name;
        }

    }
}
