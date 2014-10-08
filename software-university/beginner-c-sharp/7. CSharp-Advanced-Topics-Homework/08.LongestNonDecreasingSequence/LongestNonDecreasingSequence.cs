using System;
using System.Linq;
using System.Collections.Generic;

class LongestNonDecreasingSequence
{
    static bool isDecreasing(string sequence)
    {
        string[] rawNumbers = sequence.Trim().Split();

        for (int i = 0; i < rawNumbers.Length - 1; i++)
        {
            if (int.Parse(rawNumbers[i]) > int.Parse(rawNumbers[i + 1])) return false;
        }

        return true;
    }

    static void Main(string[] args)
    {
        string[] rawNumbers = Console.ReadLine().Split();
        string longestSequence = string.Empty;
        int longestSequenceCount = 0;

        for (int i = 1; i < (int)Math.Pow(2, rawNumbers.Length); i++)
        {
            string indexes = Convert.ToString(i, 2).PadLeft(rawNumbers.Length, '0');
            string currentSequence = "";

            for (int j = 0; j < indexes.Length; j++)
            {
                if (indexes[j].Equals('1'))
                {
                    currentSequence += rawNumbers[j] + " ";
                }
            }

            if (isDecreasing(currentSequence))
            {
                if (currentSequence.Split().Length > longestSequenceCount)
                {
                    longestSequenceCount = currentSequence.Split().Length;
                    longestSequence = currentSequence;
                }
            }
        }

        Console.WriteLine(longestSequence);
    }
}