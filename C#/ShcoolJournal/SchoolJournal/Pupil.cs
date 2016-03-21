using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using System.Xml.Serialization;
namespace SchoolJournal
{
    [Serializable]
    public class Pupil : Human
    {

        private static int IDALLPupil = 0;
        private int pupilID;
        [XmlAttribute]
        public int PupilID
        {
             get { return pupilID; }
            
             set
            {
                pupilID = value;
                if (value >= IDALLPupil) IDALLPupil = ++value;
            }
        }
        public Pupil()
        {
            name = default(string);
            PupilID = IDALLPupil++;
        }
        public Pupil(string name)
            : this()
        {
            this.name = name;
        }

    }
}
