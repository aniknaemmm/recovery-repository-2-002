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
    public class Mark
    {
        public int? value;
        [XmlIgnore]
        public Pupil pupil;
        [XmlIgnore]
        public Teacher teacher;
        public int? pupilID;
        public int? teacherID;
        public string for_what;

        public Mark()
        {
            pupil = default(Pupil);
            teacher = default(Teacher);
            for_what = default(string);
        }

        public Mark(Teacher teacher, Pupil pupil, string for_what, int value)
        {
            this.teacher = teacher;
            this.pupilID = pupil.PupilID;
            this.teacherID = teacher.TeacherID;
            this.pupil = pupil;
            this.for_what = for_what;
            this.value = value;
        }

        public void Show()
        {
            Console.WriteLine("{0} take {1} for {2}.", pupil.name, value, for_what);
        }
    }
}
