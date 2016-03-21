using System;
using System.Xml;
using XML;
class MyApp
{
    static void displayNode(XmlNode node, int level = 0)
    {

        if (node.NodeType == XmlNodeType.Element)
        {
            Console.Write(new String(' ', level) + node.Name);
            foreach (XmlAttribute a in node.Attributes)
            {
                Console.Write(" {0}='{1}'", a.Name, a.Value);
            }
            Console.WriteLine();
        }
        if (node.NodeType == XmlNodeType.Text)
        {
            Console.WriteLine(new String(' ', level) + '*' + node.Value + '*');
        }


        foreach (XmlNode child in node.ChildNodes)
        {
            displayNode(child, level + 1);
        }
    }


    static void Main()
    {
        XmlDocument doc = new XmlDocument();
        int count = 0;
        doc.Load(@"C:\Users\oleg\Desktop\course\HrebenkoDz\C#\XML\doc\Cars.xml");
        XmlNode root = doc.ChildNodes[1];
        Automobile[] arrayAutomobile = new Automobile[root.ChildNodes.Count];
                
        foreach (XmlNode nodeCar in root.ChildNodes)
        {
            arrayAutomobile[count++] = new Automobile(nodeCar);
        }


        foreach (var car in arrayAutomobile)
        {
            Console.WriteLine(car.year == null ? "not year" : car.year.ToString());
        }
    }
}
