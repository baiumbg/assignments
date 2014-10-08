using System;

class CheckForPrime
{
    static bool isPrime(int number)
    {
        if (number == 0 || number == 1) return false;
        for (int i = 2; i < number / 2; i++)
        {
            if (number % i == 0) return false;
        }
        return true;
    }
    static void Main()
    {
        int number = int.Parse(Console.ReadLine());
        Console.WriteLine(isPrime(number));
    }
}