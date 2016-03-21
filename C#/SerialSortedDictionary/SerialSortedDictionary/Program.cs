using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using System.Xml.Linq;
using System.Xml.Serialization;

namespace SerialSortedDictionary
{
    class Program
    {
        static void Main(string[] args)
        {
            var dict = new SerializableDictionary< string,List<string>>();
            List<string> hh = new List<string> { "tt", "tewewt" };
            dict.Add("Grass", hh);
            dict.Add("Snow", hh);
            dict.Add("Sky", hh);
            dict.Add("Tomato", hh);
            dict.Add("Coal", hh);
            dict.Add("Mud", hh);

            var serializer = new System.Xml.Serialization.XmlSerializer(dict.GetType());

            // Load memory stream with this objects xml representation
            XmlWriter xmlWriter = null;
         
                xmlWriter = XmlWriter.Create("tt.xml");
                serializer.Serialize(xmlWriter, dict);
                xmlWriter.Close();
          

            XDocument doc = XDocument.Load("tt.xml");
          
            var outDict = serializer.Deserialize(new StreamReader("tt.xml"));
      
            Console.ReadKey();
                //    XmlSerializer serializer = new XmlSerializer(typeof(SortedDictionary<int,int>));
                //    serializer.Serialize(writer, fred);
                //


        }
    }
}
