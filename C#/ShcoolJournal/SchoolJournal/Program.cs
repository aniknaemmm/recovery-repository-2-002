using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace SchoolJournal
{
    class Program
    {
        static void Main(string[] args)
        {
            List<Teacher> teachers = new List<Teacher> { new Teacher("Maks"), new Teacher("ne maks") };

            List<Pupil> temp = new List<Pupil> { new Pupil("Oleg"), new Pupil("Olya"), new Pupil("Andrew"), new Pupil("Tupica") };
            List<PupilsGroup> pupils_group = new List<PupilsGroup>{new PupilsGroup("P11014", temp)};

            List<string> tempTopics = new List<string> { "firstTopic", "SecondTopic", "Last Topic" };
            List<Subject> subjects = new List<Subject>{new Subject("C#", tempTopics)};


            List<Lesson> lesons = new List<Lesson> { new Lesson(subjects[0], subjects[0].topics[0], teachers[0] , pupils_group[0]), new Lesson(subjects[0], subjects[0].topics[0], teachers[1], pupils_group[0]) };
            lesons[1].ManageLesson();
            lesons[0].ManageLesson();

           

            teachers.SerializableTeacher("teacher.xml");
            pupils_group.SerializableGroup("group.xml");
            lesons.SerializableLesson("lessons.xml");
            subjects.SerializableSubject("subject.xml");

            List<Teacher> tt = DeSerializable.DeSerializableTeacher("teacher.xml");
            List<PupilsGroup> gg = DeSerializable.DeSerializableGroup("group.xml");
            List<Subject> ff = DeSerializable.DeSerializableSubject("subject.xml");
            List<Lesson> dd = DeSerializable.DeSerializableLesson("lessons.xml",tt,gg,ff);
            dd[1].ManageLesson();
            dd[0].ManageLesson();


            Console.ReadLine();
        }




    }
}
