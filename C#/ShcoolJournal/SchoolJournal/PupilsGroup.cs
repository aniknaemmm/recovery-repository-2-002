using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SchoolJournal
{
    [Serializable]
    public class PupilsGroup
    {
        public string name;
        public List<Pupil> pupils;
       
         public PupilsGroup()
        {
            name = default(string);
            pupils = new List<Pupil>();
        }

        public PupilsGroup(string name, List<Pupil> pupil)
            : this()
        {
            this.name = name;
            pupils = pupil;
           
        }
    }
}
