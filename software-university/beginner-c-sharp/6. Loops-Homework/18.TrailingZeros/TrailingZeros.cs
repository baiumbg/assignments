using System;

class TrailingZeros
{
    static void Main()
    {
        int N = int.Parse(Console.ReadLine());
        int power = 1, trailingZeros = 0;
        while (N / Math.Pow(5, power) > 1)
        {
            trailingZeros += (N / (int)Math.Pow(5, power));
            power++;
        }
        Console.WriteLine(trailingZeros);
    }
}