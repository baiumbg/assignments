using System;

class QuadraticEquation
{
    static void Main()
    {
        double a, b, c, D;
        a = double.Parse(Console.ReadLine());
        b = double.Parse(Console.ReadLine());
        c = double.Parse(Console.ReadLine());
        D = b * b - 4 * a * c;
        if (D > 0)
        {
            Console.WriteLine("x1={0}; x2={1}", (-b - Math.Sqrt(D)) / (2 * a), (-b + Math.Sqrt(D)) / (2 * a));
        }
        else if(D == 0)
        {
            Console.WriteLine("x1=x2={0}", (-b + Math.Sqrt(D)) / (2 * a));
        }
        else
        {
            Console.WriteLine("no real roots");
        }
    }
}