using System;
using System.Linq;
using System.Collections.Generic;

class JoinLists
{
    static void Main()
    {
        string[] firstLineNumbers = Console.ReadLine().Split();
        string[] secondLineNumbers = Console.ReadLine().Split();
        List<int> endResult = new List<int>();
        foreach(var item in firstLineNumbers)
        {
            if (!endResult.Contains(int.Parse(item))) endResult.Add(int.Parse(item));
        }
        foreach(var item in secondLineNumbers)
        {
            if (!endResult.Contains(int.Parse(item))) endResult.Add(int.Parse(item));
        }
        endResult.Sort();
        foreach(var item in endResult)
        {
            Console.Write("{0} ", item);
        }
        Console.WriteLine();
    }
}