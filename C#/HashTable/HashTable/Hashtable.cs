using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HashTable
{
    class Hashtable<Key, Value>
    {
        private Dictionary<Key, Value>[] data;
        private int count, memory;

        public Hashtable(int elements)
        {
            data = new Dictionary<Key, Value>[elements * 6];
            count = 0;
            memory = elements * 6;
        }

        public Value this[Key key]
        {
            set
            {
                int ihash = Math.Abs(key.GetHashCode()) % memory;
                if (data[ihash] == null)
                {
                    data[ihash] = new Dictionary<Key, Value>();

                }
                if (data[ihash].ContainsKey(key))
                {
                    data[ihash][key] = value;
                }
                else
                {
                    data[ihash].Add(key, value);
                    count++;
                }

            }

            get
            {
                int ihash = Math.Abs(key.GetHashCode()) % memory;


                if (data[ihash] != null && data[ihash].ContainsKey(key))
                    return data[ihash][key];
                throw new IndexOutOfRangeException("out of range hash table");
            }

        }

        public int Count
        {
            get { return count; }
        }



        public void print()
        {
            foreach (var pos in data)
            {
                if (pos != null)

                    foreach (var element in pos)
                    {
                        Console.WriteLine("data[" + element.Key + "] = " + element.Value);
                    }

            }
        }

        public void remove(Key key)
        {
            int ihash = Math.Abs(key.GetHashCode()) % memory;

            if (data[ihash] != null && data[ihash].ContainsKey(key))
            {
                data[ihash].Remove(key);
                --count;
            }
        }

    }
}
