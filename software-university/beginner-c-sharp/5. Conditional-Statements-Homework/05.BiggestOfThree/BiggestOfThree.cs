using System;

class BiggestOfThree
{
    static void Main()
    {
        double a, b, c;
        a = double.Parse(Console.ReadLine());
        b = double.Parse(Console.ReadLine());
        c = double.Parse(Console.ReadLine());
        if(a >= b && a >= c)
        {
            Console.WriteLine(a);
        }
        else if (b >= a && b >= c)
        {
            Console.WriteLine(b);
        }
        else Console.WriteLine(c);
    }
}