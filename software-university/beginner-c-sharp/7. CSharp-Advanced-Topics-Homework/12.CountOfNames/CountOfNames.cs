using System;
using System.Linq;
using System.Collections.Generic;

class CountOfNames
{
    static void Main()
    {
        string[] names = Console.ReadLine().Split();
        SortedDictionary<string, int> namesDict = new SortedDictionary<string, int>();

        foreach (var l in names)
        {
            if (!namesDict.ContainsKey(l)) namesDict.Add(l, 0);
            namesDict[l]++;
        }

        foreach (var l in namesDict.Keys)
        {
            Console.WriteLine("{0} -> {1}", l, namesDict[l]);
        }

    }
}