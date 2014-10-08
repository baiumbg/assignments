using System;
using System.Collections.Generic;

class PrimesInRange
{
    static bool IsPrime(long n)
    {
        if (n == 0 || n == 1) return false;
        for (long i = 2; i <= Math.Sqrt(n); i++)
        {
            if (n % i == 0) return false;
        }
        return true;
    }
    static List<int> FindPrimesInRange(int startNum, int endNum)
    {
        List<int> primes = new List<int>();
        for (int i = startNum; i <= endNum; i++)
        {
            if (IsPrime(i)) primes.Add(i);
        }
        return primes;
    }
    static void PrintList(List<int> l)
    {
        if (l.Count == 0)
        {
            Console.WriteLine("(empty list)");
            return;
        }
        for (int i = 0; i < l.Count - 1; i++)
        {
            Console.Write("{0}, ", l[i]);
        }
        Console.WriteLine(l[l.Count - 1]);
    }
    static void Main()
    {
        int start = int.Parse(Console.ReadLine());
        int end = int.Parse(Console.ReadLine());
        PrintList(FindPrimesInRange(start, end));
    }
}