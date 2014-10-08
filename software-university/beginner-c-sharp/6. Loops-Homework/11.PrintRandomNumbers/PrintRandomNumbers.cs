using System;
using System.Linq;

class PrintRandomNumbers
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int min = int.Parse(Console.ReadLine());
        int max = int.Parse(Console.ReadLine());
        Random rand = new Random();
        for(int i=0;i<n;i++)
        {
            Console.WriteLine(rand.Next(min, max));
        }
    }
}