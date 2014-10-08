using System;

class MultiplicationSign
{
    static void Main()
    {
        double a, b, c;
        a = double.Parse(Console.ReadLine());
        b = double.Parse(Console.ReadLine());
        c = double.Parse(Console.ReadLine());
        if (a == 0 || b == 0 || c == 0)
        {
            Console.WriteLine("0");
        }
        else if ((a < 0 && b < 0 && c > 0) || (a > 0 && b < 0 && c < 0) || (a < 0 && b > 0 && c < 0))
        {
            Console.WriteLine("+");
        }
        else if (a > 0 && b > 0 && c > 0)
        {
            Console.WriteLine("+");
        }
        else if ((a > 0 && b > 0 && c < 0) || (a > 0 && b < 0 && c > 0) || (a < 0 && b > 0 && c > 0))
        {
            Console.WriteLine("-");
        }
        else if(a < 0 && b < 0 && c < 0)
        {
            Console.WriteLine("-");
        }
    }
}