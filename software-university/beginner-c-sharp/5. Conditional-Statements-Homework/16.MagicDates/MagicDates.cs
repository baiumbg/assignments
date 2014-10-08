using System;

class MagicDates
{
    static int calculateWeight(DateTime t)
    {
        int[] digits = new int[8];
        digits[0] = t.Day / 10;
        digits[1] = t.Day % 10;
        digits[2] = t.Month / 10;
        digits[3] = t.Month % 10;
        digits[4] = t.Year / 1000;
        digits[5] = (t.Year / 100) % 10;
        digits[6] = (t.Year / 10) % 10;
        digits[7] = t.Year % 10;
        int weight = 0;
        for (int i = 0; i < 7; i++)
        {
            for (int j = i + 1; j < 8; j++)
            {
                weight += digits[i] * digits[j];
            }
        }
        return weight;
    }
    static void Main()
    {
        DateTime start = new DateTime(int.Parse(Console.ReadLine()), 1, 1);
        DateTime end = new DateTime(int.Parse(Console.ReadLine()), 12, 31);
        int magicWeight = int.Parse(Console.ReadLine());
        bool foundMagicDate = false;
        for (DateTime i = start; i.CompareTo(end) <= 0; i = i.AddDays(1))
        {
            if (calculateWeight(i) == magicWeight)
            {
                Console.WriteLine("{0:D2}-{1:D2}-{2}", i.Day, i.Month, i.Year);
                foundMagicDate = true;
            }
        }
        if (!foundMagicDate) Console.WriteLine("No");
    }
}