using System;

class SwapVariables
{
    static void Main()
    {
        int a = 5, b = 10, c;
        Console.WriteLine("Before:\na = {0}, b = {1}\n", a, b);
        c = a;
        a = b;
        b = c;
        Console.WriteLine("After:\na = {0}, b = {1}", a, b);
    }
}