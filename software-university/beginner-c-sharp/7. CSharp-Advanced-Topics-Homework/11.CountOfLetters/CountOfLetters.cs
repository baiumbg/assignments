using System;
using System.Linq;
using System.Collections.Generic;

class CountOfLetters
{
    static void Main()
    {
        string[] letters = Console.ReadLine().Split();
        SortedDictionary<string, int> lettersDict = new SortedDictionary<string, int>();

        foreach(var l in letters)
        {
            if (!lettersDict.ContainsKey(l)) lettersDict.Add(l, 0);
            lettersDict[l]++;
        }

        foreach(var l in lettersDict.Keys)
        {
            Console.WriteLine("{0} -> {1}", l, lettersDict[l]);
        }

    }
}