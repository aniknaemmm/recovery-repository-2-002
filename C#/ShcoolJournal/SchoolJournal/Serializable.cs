using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;
namespace SchoolJournal
{
    public static class Serializable
    {
        public static void SerializableTeacher(this List<Teacher> teachers, string addr)
        {
            XmlSerializer serializer = new XmlSerializer(typeof(List<Teacher>));

            using (TextWriter writer = new StreamWriter(addr))
            {
                serializer.Serialize(writer, teachers);
            }
        }
        public static void SerializableGroup(this List<PupilsGroup> Groups, string addr)
        {
            XmlSerializer serializer = new XmlSerializer(typeof(List<PupilsGroup>));

            using (TextWriter writer = new StreamWriter(addr))
            {
                serializer.Serialize(writer, Groups);
            }
        }
        public static void SerializableSubject(this List<Subject> subjects, string addr)
        {
            XmlSerializer serializer = new XmlSerializer(typeof(List<Subject>));

            using (TextWriter writer = new StreamWriter(addr))
            {
                serializer.Serialize(writer, subjects);
            }
        }
        public static void SerializableLesson(this List<Lesson> lessons, string addr)
        {
            XmlSerializer serializer = new XmlSerializer(typeof(List<Lesson>));

            using (TextWriter writer = new StreamWriter(addr))
            {
                serializer.Serialize(writer, lessons);
            }
        }

    }
}
