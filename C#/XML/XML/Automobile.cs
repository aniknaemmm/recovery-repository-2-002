using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace XML
{
    class Automobile
    {

        public string color, attribColor, model, Manufactured, img, hash;
        public int? speed, year;
        private Dictionary<string, string> attribs;

        public Automobile() 
        {

        }



        public Automobile(XmlNode node)
        {
            attribs = new Dictionary<string, string>();

            foreach (XmlNode attr in node.Attributes)
            {
                switch (attr.Name)
                {
                    case "Image":
                        img = attr.Value;
                        break;
                    case "Year":
                        year = Int32.Parse(attr.Value);
                        break;
                    case "hash":
                        hash = attr.Value;
                        break;
                    default:
                        break;
                }
            }

            foreach (XmlNode element in node.ChildNodes)
            {
                if (element.NodeType == XmlNodeType.Element)
                {
                    switch (element.Name)
                    {
                        case "Color":

                            foreach (XmlNode nNode in element)
                            {
                                if (nNode.NodeType == XmlNodeType.Text)
                                    color = nNode.Value;
                            }

                            chekAtrib(element);

                            if (attribs.Count != 0)
                                attribColor = attribs.First().Value;

                            attribs.Clear();

                            break;

                        case "Model":

                            foreach (XmlNode nNode in element)
                            {
                                if (nNode.NodeType == XmlNodeType.Text)
                                    model = nNode.Value;
                            }

                            break;

                        case "Manufactured":

                            foreach (XmlNode nNode in element)
                            {
                                if (nNode.NodeType == XmlNodeType.Text)
                                    Manufactured = nNode.Value;
                            }

                            break;

                        case "Speed":

                            foreach (XmlNode nNode in element)
                            {
                                if (nNode.NodeType == XmlNodeType.Text)
                                    speed = Int32.Parse(nNode.Value);
                            }

                            break;

                        case "Year":

                            foreach (XmlNode nNode in element)
                            {
                                if (nNode.NodeType == XmlNodeType.Text)
                                    year = Int32.Parse(nNode.Value);
                            }

                            break;

                        default:

                            break;
                    }

                }
            }

        }


        private bool chekAtrib(XmlNode node)
        {
            if (node.Attributes.Count == 0)
                return false;

            foreach (XmlAttribute nodeAtrrib in node.Attributes)
            {
                attribs.Add(nodeAtrrib.Name, nodeAtrrib.Value);
            }

            return true;
        }




    }
}
