using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace SchoolJournal
{
    [Serializable]
    public class Lesson
    {
        [XmlAttribute]
        public int teacherID;
        [XmlAttribute]
        public string nameGr;
        [XmlIgnore]
        public Subject subject;
        [XmlIgnore]
        public Teacher teacher;
        [XmlIgnore]
        public PupilsGroup pupil_group;
        
        public string topic;
        public List<Mark> marks;
        
        public Lesson()
        {
            topic       = default(string);
            nameGr      = default(string);
            teacher     = default(Teacher);
            subject     = default(Subject);
            teacherID   = default(int);
            pupil_group = default(PupilsGroup);

            marks       = new List<Mark>();
        }

        public Lesson(Subject subject, string theme, Teacher teacher, PupilsGroup pupil_group)
            : this()
        {
            this.topic       = theme;
            this.teacher     = teacher;
            this.subject     = subject;
            this.pupil_group = pupil_group;
            this.nameGr      = pupil_group.name;
            this.teacherID   = teacher.TeacherID;

        }

        public void ManageLesson()
        {
            Console.WriteLine("Lesson is begins!");

            Mark mark1 = new Mark(teacher, pupil_group.pupils[0], "home work", 10);
            Mark mark2 = new Mark(teacher, pupil_group.pupils[1], "class work", 10);
            Mark mark3 = new Mark(teacher, pupil_group.pupils[2], "good actions", 10);
            Mark mark4 = new Mark(teacher, pupil_group.pupils[3], "home work", 10);

            marks.Add(mark1);
            marks.Add(mark2);
            marks.Add(mark3);
            marks.Add(mark4);

            foreach (var mark in marks)
            {
                mark.Show();
            }

            Console.WriteLine("Lesson is finished!");
        }


    }
}
