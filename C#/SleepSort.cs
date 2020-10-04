//  Sleep_Sort Algorithm.
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;
 
class Program
{
    static void ThreadStart(object item)
    {
        Thread.Sleep(1000 * (int)item);
        Console.WriteLine(item);
    }
 
    static void SleepSort(IEnumerable<int> items)
    {
        foreach (var item in items)
        {
            new Thread(ThreadStart).Start(item);
        }
    }
 
    static void Main(string[] arguments)
    {
        SleepSort(arguments.Select(int.Parse));
    }
}

/* for input 11,6,2,90,23
 * Output is 2 6 11 23 90
 * As input is dynamic so  complexity for can be different
 * Complexity for the sleepSort method : O(NlogN + max(input))
 * Space complexity and time complexity both  are calculated as the function of input size(n).
 */