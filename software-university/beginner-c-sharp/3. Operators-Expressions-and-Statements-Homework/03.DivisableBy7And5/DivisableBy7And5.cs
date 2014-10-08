using System;

class DivisableBy7And5
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        Console.WriteLine(n%5 == 0 && n%7 == 0);
    }
}