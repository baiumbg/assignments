using System;

class BiggestOfFive
{
    static void Main()
    {
        double a, b, c, d, e;
        a = double.Parse(Console.ReadLine());
        b = double.Parse(Console.ReadLine());
        c = double.Parse(Console.ReadLine());
        d = double.Parse(Console.ReadLine());
        e = double.Parse(Console.ReadLine());
        if (a >= b && a >= c && a >= d && a >= e)
        {
            Console.WriteLine(a);
        }
        else if (b >= a && b >= c && b >= d && b >= e)
        {
            Console.WriteLine(b);
        }
        else if (c >= a && c >= b && c >= d && c >= e)
        {
            Console.WriteLine(c);
        }
        else if (d >= a && d >= b && d >= c && d >= e)
        {
            Console.WriteLine(d);
        }
        else Console.WriteLine(e);
    }
}