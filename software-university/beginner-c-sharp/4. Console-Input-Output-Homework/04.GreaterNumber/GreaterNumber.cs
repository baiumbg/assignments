using System;

class Program
{
    static void Main()
    {
        double a, b;
        a = double.Parse(Console.ReadLine());
        b = double.Parse(Console.ReadLine());
        Console.WriteLine(a > b ? a : b);
    }
}