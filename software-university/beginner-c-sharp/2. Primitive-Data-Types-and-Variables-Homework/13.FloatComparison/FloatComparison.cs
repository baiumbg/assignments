using System;

class FloatComparison
{
    static void Main()
    {
        // NOTE: Use your system's format for inputting decimals
        double a, b, eps = 0.000001;
        Console.WriteLine("Enter first number to be compared: ");
        a = Double.Parse(Console.ReadLine());
        Console.WriteLine("Enter second number to be compared: ");
        b = Double.Parse(Console.ReadLine());
        Console.WriteLine(Math.Abs(a - b) < eps ? "Equal" : "Not equal");
    }
}