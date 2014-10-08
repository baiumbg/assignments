using System;

class MinMaxSumAverage
{
    static void Main()
    {
        int? min = null, max = null;
        int sum = 0;
        double average = 0;
        int n = int.Parse(Console.ReadLine());
        for (int i = 0; i < n; i++)
        {
            if (min == null && max == null)
            {
                min = int.Parse(Console.ReadLine());
                max = min;
                sum += (int)min;
                average += (int)min;
            }
            else
            {
                int num = int.Parse(Console.ReadLine());
                if (num < min) min = num;
                if (num > max) max = num;
                sum += num;
                average += num;
            }
        }
        average /= n;
        Console.WriteLine("min = {0}\nmax = {1}\nsum = {2}\navg = {3:F2}\n", min, max, sum, average);
    }
}