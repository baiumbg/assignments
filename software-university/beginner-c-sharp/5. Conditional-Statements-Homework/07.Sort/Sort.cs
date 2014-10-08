using System;

class Sort
{
    static void Main()
    {
        double a, b, c;
        a = double.Parse(Console.ReadLine());
        b = double.Parse(Console.ReadLine());
        c = double.Parse(Console.ReadLine());
        if (a >= b && a >= c)
        {
            if (b >= c) Console.WriteLine("{0} {1} {2}", a, b, c);
            else Console.WriteLine("{0} {1} {2}", a, c, b);
        }
        else if (b >= a && b >= c)
        {
            if (a >= c) Console.WriteLine("{0} {1} {2}", b, a, c);
            else Console.WriteLine("{0} {1} {2}", b, c, a);
        }
        else
        {
            if (a >= b) Console.WriteLine("{0} {1} {2}", c, a, b);
            else Console.WriteLine("{0} {1} {2}", c, b, a);
        }
    }
}