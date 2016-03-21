using System;
using System.Collections.Generic;
using System.IO;
using System.Xml;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;
using System.Runtime.Serialization.Formatters.Binary;

namespace Serializable
{
    class Program
    {
        static void Main(string[] args)
        {
            Program t = new Program();
            Pupils[] ttt = new Pupils[] { new Pupils(1, "rer"), new Pupils(2, "dfdfd") };
            t.createXML(ttt, "xml1.xml");
            Pupils[] tttt = new Pupils[2];
            t.readXML(tttt, "xml1.xml");
        }


        private void CreatePO(Pupils[] rext, string filename)
        {
            Stream TestFileStream = File.Create(filename);
            BinaryFormatter serializer = new BinaryFormatter();
            serializer.Serialize(TestFileStream, rext);
            TestFileStream.Close();
        }
        private void disPO(Pupils[] rext, string filename)
        {
            if (File.Exists(filename))
            {
                Stream TestFileStream = File.OpenRead(filename);
                BinaryFormatter deserializer = new BinaryFormatter();
                rext = (Serializable.Pupils[])deserializer.Deserialize(TestFileStream);
                TestFileStream.Close();
            }

            foreach (var rexts in rext)
            {
                Console.WriteLine(rexts.name + rexts.year);
            }
        }

        private void createXML(Pupils[] rext, string filename)
        {
            // Create an instance of the XmlSerializer class;
            // specify the type of object to serialize.
            XmlSerializer serializer =
            new XmlSerializer(typeof(Pupils[]));
            TextWriter writer = new StreamWriter(filename);

            serializer.Serialize(writer, rext);
            writer.Close();
        }

        protected void readXML(Pupils[] rext, string filename)
        {
            // Create an instance of the XmlSerializer class;
            // specify the type of object to be deserialized.
            XmlSerializer serializer = new XmlSerializer(typeof(Pupils[]));


            // A FileStream is needed to read the XML document.
            FileStream fs = new FileStream(filename, FileMode.Open);
            // Declare an object variable of the type to be deserialized.

            /* Use the Deserialize method to restore the object's state with
            data from the XML document. */
            rext = (Serializable.Pupils[])serializer.Deserialize(fs);
            // Read the order date.
            foreach (var rexts in rext)
            {
                Console.WriteLine(rexts.name + rexts.year);
            }

            // Read the shipping address.

        }





    }
}