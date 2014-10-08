using System;

class Pairs
{
    static void Main()
    {
        string input = Console.ReadLine();
        string[] rawNumbers = input.Split();
        int n = rawNumbers.Length;
        int[] pairs = new int[n / 2];
        bool allEqual = true;

        for (int i = 0; i < n; i+=2)
            pairs[i/2] = int.Parse(rawNumbers[i]) + int.Parse(rawNumbers[i+1]);

        if (n == 2)
        {
            Console.WriteLine("Yes, value={0}", pairs[0]);
            return;
        }

        for (int i = 0; i < (n / 2) - 1; i++)
        {
            for (int j = i + 1; j < n / 2; j++)
            {
                if (pairs[i] != pairs[j]) allEqual = false;
            }
        }

        if (allEqual)
        {
            Console.WriteLine("Yes, value={0}", pairs[0]);
            return;
        }

        int maxDiff = 0;

        for (int i = 0; i < (n / 2) - 1; i++)
        {
            int currDiff = Math.Abs(pairs[i] - pairs[i + 1]);
            if (currDiff > maxDiff) maxDiff = currDiff;
        }

        Console.WriteLine("No, maxdiff={0}", maxDiff);
    }
}