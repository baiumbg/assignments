using System;

class CalculateCombinations
{
    static double factorial(int number)
    {
        if (number == 0) return 1;
        double fact = 1;
        for(int i=1;i<=number;i++)
        {
            fact *= i;
        }
        return fact;
    }
    static void Main()
    {
        int n = int.Parse(Console.ReadLine()), k = int.Parse(Console.ReadLine());
        Console.WriteLine(factorial(n) / (factorial(k) * factorial(n-k)));
    }
}