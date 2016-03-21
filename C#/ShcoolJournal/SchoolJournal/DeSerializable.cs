using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;
using System.IO;

namespace SchoolJournal
{
    public static class DeSerializable
    {

        public static List<Teacher> DeSerializableTeacher(string addr)
        {
            if (!File.Exists(addr)) throw new FileNotFoundException("no file");

            List<Teacher> buf;
            XmlSerializer deserializer = new XmlSerializer(typeof(List<Teacher>));

            using (var file = new StreamReader(addr))
            {
                buf = (List<Teacher>)deserializer.Deserialize(file);
            }

            return buf;
        }
        public static List<PupilsGroup> DeSerializableGroup(string addr)
        {
            if (!File.Exists(addr)) throw new FileNotFoundException("no file");

            List<PupilsGroup> buf;
            XmlSerializer deserializer = new XmlSerializer(typeof(List<PupilsGroup>));

            using (var file = new StreamReader(addr))
            {
                buf = (List<PupilsGroup>)deserializer.Deserialize(file);
            }


            return buf;
        }
        public static List<Subject> DeSerializableSubject(string addr)
        {
            if (!File.Exists(addr)) throw new FileNotFoundException("no file");

            List<Subject> buf;
            XmlSerializer deserializer = new XmlSerializer(typeof(List<Subject>));

            using (var file = new StreamReader(addr))
            {
                buf = (List<Subject>)deserializer.Deserialize(file);
            }

            return buf;
        }
        public static List<Lesson> DeSerializableLesson(string addr, List<Teacher> teacher, List<PupilsGroup> group, List<Subject> subjects)
        {
            if (!File.Exists(addr)) throw new FileNotFoundException("no file");
            List<Lesson> buf;

            XmlSerializer deserializer = new XmlSerializer(typeof(List<Lesson>));

            using (var file = new StreamReader(addr))
            {
                buf = (List<Lesson>)deserializer.Deserialize(file);
            }

            foreach (var cur in buf)
            {
                foreach (var tech in teacher)
                {
                    if (cur.teacherID == tech.TeacherID)
                    {
                        cur.teacher = tech;
                        break;
                    }
                }
                foreach (var tech in group)
                {
                    if (cur.nameGr == tech.name)
                    {
                        cur.pupil_group = tech;
                        break;
                    }
                }
                foreach (var tech in subjects)
                {
                    if (cur.topic == tech.topics.Find(x => x.Contains(cur.topic)))
                    {
                        cur.subject = tech;
                        break;
                    }
                }
                foreach (var tt in cur.marks)
                {

                    foreach (var tech in teacher)
                    {
                        if (tt.teacherID == tech.TeacherID)
                        {
                            tt.teacher = tech;
                            break;
                        }
                    }

                    foreach (var tech in cur.pupil_group.pupils)
                    {
                        if (tt.pupilID == tech.PupilID)
                        {
                            tt.pupil = tech;
                            break;
                        }
                    }
                }
            }
            return buf;
        }

    }
}
