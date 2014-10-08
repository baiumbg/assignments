using System;

class HalfSum
{
    static void Main()
    {
        int firstSum = 0, secondSum = 0, n;
        n = int.Parse(Console.ReadLine());
        for (int i = 0; i < n; i++)
            firstSum += int.Parse(Console.ReadLine());
        for (int i = 0; i < n; i++)
            secondSum += int.Parse(Console.ReadLine());
        if (firstSum == secondSum)
            Console.Write("Yes, sum={0}", firstSum);
        else
            Console.Write("No, diff={0}", Math.Abs(firstSum - secondSum));
    }
}