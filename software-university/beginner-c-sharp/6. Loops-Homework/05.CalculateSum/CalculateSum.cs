using System;

class CalculateSum
{
    static void Main()
    {
        double sum = 1, factorial = 1;
        int n = int.Parse(Console.ReadLine()), x = int.Parse(Console.ReadLine());
        for(int i=1;i<=n;i++)
        {
            factorial *= i;
            sum += factorial / Math.Pow(x, i);
        }
        Console.WriteLine("{0:F5}", sum);
    }
}