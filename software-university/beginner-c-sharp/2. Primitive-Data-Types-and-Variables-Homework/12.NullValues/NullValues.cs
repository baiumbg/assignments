using System;

class NullValues
{
    static void Main()
    {
        int? a = null;
        double? b = null;
        Console.WriteLine("a - {0}, b - {1}", a, b);
        a += 1;
        b += 3;
        Console.WriteLine("a - {0}, b - {1}", a, b);
        a += null;
        b += null;
        Console.WriteLine("a - {0}, b - {1}", a, b);
    }
}