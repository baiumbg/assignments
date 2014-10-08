using System;

class DifferenceBetweenDates
{
    static void Main()
    {
        DateTime start = DateTime.Parse(Console.ReadLine());
        DateTime end = DateTime.Parse(Console.ReadLine());
        Console.WriteLine((end - start).Days);
    }
}