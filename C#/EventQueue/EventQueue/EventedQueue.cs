using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EventQueue
{
    delegate void TransportEvent(uint time);
    class EventedQueue
    {

        private SortedDictionary<uint, LinkedList<TransportEvent>> queue;

        public EventedQueue()
        {
            queue = new SortedDictionary<uint, LinkedList<TransportEvent>>();
        }

        //добавить событие в очередь на заданное время
        public void AddEvent(uint time, TransportEvent transportEvent)
        {
            if (queue.ContainsKey(time) == false)
            {
                queue[time] = new LinkedList<TransportEvent>();
            }

            queue[time].AddLast(transportEvent);
        }
        //взять первое событие из очереди
        public TransportEvent PopEvent(out uint time)
        {

            if (queue.Count != 0)
            {
                TransportEvent temp = queue.Values.First().First.Value;
                time = queue.Keys.First();
                RemoveEvent();
                return temp;
            }
            time = 0;
            return null;
        }

        //удалить событие
        public void RemoveEvent()
        {
            queue.Values.First().RemoveFirst();
            if (queue.Values.First().Count == 0)
            {
                queue.Remove(queue.Keys.First());
            }
        }

    }
}
