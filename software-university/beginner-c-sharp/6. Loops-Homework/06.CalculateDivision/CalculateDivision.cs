using System;

class CalculateDivision
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine()), k = int.Parse(Console.ReadLine());
        double factorialN = 1, factorialK = 1;
        for (int i = 1; i <= n; i++)
        {
            if (i <= k) factorialK *= i;
            factorialN *= i;
        }
        Console.WriteLine(factorialN/factorialK);
    }
}