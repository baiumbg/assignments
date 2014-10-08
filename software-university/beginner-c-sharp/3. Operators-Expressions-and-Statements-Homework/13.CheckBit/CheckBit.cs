using System;

class CheckBit
{
    static void Main()
    {
        int number = int.Parse(Console.ReadLine());
        int bitPosition = int.Parse(Console.ReadLine());
        Console.WriteLine((number & (1 << bitPosition)) != 0);
    }
}