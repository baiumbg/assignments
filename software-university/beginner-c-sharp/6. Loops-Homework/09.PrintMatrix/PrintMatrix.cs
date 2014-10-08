using System;

class PrintMatrix
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= n + i - 1; j++)
            {
                Console.Write("{0} ", j);
            }
            Console.WriteLine();
        }
    }
}