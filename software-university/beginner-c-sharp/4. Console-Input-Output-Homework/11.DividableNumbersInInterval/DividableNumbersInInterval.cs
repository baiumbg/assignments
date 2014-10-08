using System;

class DividableNumbersInInterval
{
    static void Main()
    {
        int start, end, count = 0;
        start = int.Parse(Console.ReadLine());
        end = int.Parse(Console.ReadLine());
        for (int i = start; i <= end; i++)
        {
            if (i % 5 == 0) count++;
        }
        Console.WriteLine(count);
    }
}