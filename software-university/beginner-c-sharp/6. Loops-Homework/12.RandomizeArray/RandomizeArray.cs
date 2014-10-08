using System;
using System.Linq;

class RandomizeArray
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[] numbers = new int[n];
        Random rand = new Random();
        for (int i = 0; i < n; i++)
        {
            numbers[i] = i + 1;
        }
        for (int i = 0; i < n; i++)
        {
            int randIndex = rand.Next(0, n - 1);
            int temp = numbers[i];
            numbers[i] = numbers[randIndex];
            numbers[randIndex] = temp;
        }
        for (int i = 0; i < n; i++)
        {
            Console.Write("{0} ", numbers[i]);
        }
        Console.WriteLine();
    }
}