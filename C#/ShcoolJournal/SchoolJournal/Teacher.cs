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
    public class Teacher : Human
    {
        private static int IDALLTeacher = 0;

        
        private int teacherID;
        [XmlAttribute]
        public int TeacherID
        {
             get { return teacherID; }

             set
            {
                teacherID = value;
                if (value >= IDALLTeacher) IDALLTeacher = ++value;
            }
        }

        public Teacher()
        {
            name = default(string);
            TeacherID = IDALLTeacher++;
        }
        public Teacher(string name)
            : this()
        {
            this.name = name;
        }
    }
}
