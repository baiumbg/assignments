using System;

class FibonacciNumbers
{
    static int Fib(int n)
    {
        if (n <= 0) return 1;
        if (n == 1) return 1;
        return Fib(n - 1) + Fib(n - 2);
    }
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        Console.WriteLine(Fib(n));
    }
}