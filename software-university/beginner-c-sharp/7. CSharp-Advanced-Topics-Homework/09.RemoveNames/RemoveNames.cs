using System;
using System.Linq;
using System.Collections.Generic;

class RemoveNames
{
    static void Main()
    {
        List<string> firstList = Console.ReadLine().Split().ToList();
        List<string> secondList = Console.ReadLine().Split().ToList();
        foreach(var item in secondList)
        {
            while(firstList.Contains(item))
            {
                firstList.Remove(item);
            }
        }
        foreach(var item in firstList)
        {
            Console.Write("{0} ", item);
        }
        Console.WriteLine();
    }
}