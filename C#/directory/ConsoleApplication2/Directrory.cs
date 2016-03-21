using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication2
{
    class Directrory
    {
        string sourceDirectory;
        int level;
        public Directrory(string direct)
        {
            sourceDirectory = direct;
            Directory.SetCurrentDirectory(sourceDirectory);
            level = 0;
        }

        public Directrory()
            : this(@"D:\SQLManagementStudio_x86_RUS\redist")
        {

        }

        public void GetCurrentDirectory()
        {
            Console.WriteLine(Directory.GetCurrentDirectory());
        }

        public void GetDirectories()
        {
            string[] fileEntries = Directory.GetDirectories(sourceDirectory);
            foreach (string fileName in fileEntries)
            {
                ProcessFile(fileName);
                GetDirectories(fileName);
            }

        }

        public void GetDirectories(string tempPath)
        {
            level++;
            string[] fileEntries = Directory.GetDirectories(tempPath);
            foreach (string fileName in fileEntries)
            {
                ProcessFile(fileName);
                GetDirectories(fileName);
            }
            level--;
        }


        public void ProcessFile(string path)
        {
            string prob = "╽";
            for (int i = 0; i < level; i++)
            {
                prob += "--";
            }
            if (level == 0)
            {
                Console.WriteLine("├-{0}", pars(path));
            }
            else
                Console.WriteLine("├" + prob + "{0}.", pars(path));
            string[] fileEntries = Directory.GetFiles(path);
            foreach (string fileName in fileEntries)
            {
                string dir = prob;

                dir += "  ";


                if (fileName == fileEntries[0])
                    Console.WriteLine(dir + prob + "┣{0}", pars(fileName));
                else
                    Console.WriteLine(dir + prob + "├{0}", pars(fileName));
            }

        }


        private string pars(string path)
        {
            int pos = path.LastIndexOf("\\");
            string buf = path.Substring(pos + 1);
            return buf;

        }


        public void search(string tempPath, string slovo)
        {
            string[] fileEntries = Directory.GetDirectories(tempPath);
            foreach (string fileName in fileEntries)
            {
                searchFile(fileName, slovo);
                search(fileName,slovo);
            }
        }

        private void searchFile(string fileNames, string slovo)
        {
            string[] fileEntries = Directory.GetFiles(fileNames);
            foreach (string fileName in fileEntries)
            {
                if (!File.Exists(pars(fileName)))
                {
                    string temps = pars(fileName);
                using (StreamReader temp = new StreamReader(temps))
                {
                    while (temp.Peek() >= 0)
                    {
                        if (temp.ReadLine().Contains(slovo))
                        {
                            Console.WriteLine(fileName);
                        }
                        break;

                    }
                }
            }
            }

        }



    }
}
