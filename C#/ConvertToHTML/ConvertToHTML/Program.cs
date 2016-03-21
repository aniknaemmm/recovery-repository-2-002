using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using System.Xml.XPath;
using System.Xml.Xsl;

namespace ConvertToHTML
{
    class Program
    {
        static void Main(string[] args)
        {
            XPathDocument myXPathDoc = new XPathDocument("..\\..\\group.xml");
            XslTransform myXslTrans = new XslTransform();
            myXslTrans.Load("..\\..\\s.xml");
            XmlTextWriter myWriter = new XmlTextWriter("..\\..\\result.html", null);
            myXslTrans.Transform(myXPathDoc, null, myWriter);
        }
    }
}