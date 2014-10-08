using System;

class OddOrEven
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        Console.WriteLine(n%2==0 ? "Even" : "Odd");
    }
}