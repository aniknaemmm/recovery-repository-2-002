using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SchoolJournal
{
    [Serializable]
    public class Subject
    {
        public string name;
        public List<string> topics;

        public Subject()
        {
            name = default(string);
            topics = new List<string>();
        }

        public Subject(string name, List<string> topic)
            : this()
        {
            this.name = name;
            topics = topic;
        }
    }
}
