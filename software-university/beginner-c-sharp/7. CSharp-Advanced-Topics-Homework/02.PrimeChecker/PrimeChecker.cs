using System;

class PrimeChecker
{
    // incredibly slow, but works
    static bool IsPrime(long n)
    {
        for (long i = 2; i <= Math.Sqrt(n); i++)
        {
            if (n % i == 0) return false;
        }
        return true;
    }
    static void Main()
    {
        long n = long.Parse(Console.ReadLine());
        Console.WriteLine(IsPrime(n));
    }
}