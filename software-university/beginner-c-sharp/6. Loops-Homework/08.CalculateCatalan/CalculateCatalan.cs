using System;

class CalculateCatalan
{
    static double factorial(int number)
    {
        if (number == 0) return 1;
        double fact = 1;
        for (int i = 1; i <= number; i++)
        {
            fact *= i;
        }
        return fact;
    }
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        Console.WriteLine(factorial(2 * n) / (factorial(n + 1) * factorial(n)));
    }
}