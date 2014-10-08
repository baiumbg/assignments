using System;

class Program
{
    static void Main()
    {
        int a;
        double b, c;
        a = int.Parse(Console.ReadLine());
        b = double.Parse(Console.ReadLine());
        c = double.Parse(Console.ReadLine());
        Console.WriteLine("|{0}|{1}|{2,10:0.##}|{3,-10:0.###}|", Convert.ToString(a, 16).PadRight(10), Convert.ToString(a, 2).PadLeft(10, '0'), b, c);
    }
}