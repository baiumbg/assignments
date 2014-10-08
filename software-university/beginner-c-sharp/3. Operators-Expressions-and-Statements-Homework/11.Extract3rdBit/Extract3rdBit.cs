using System;

class Extract3rdBit
{
    static void Main()
    {
        uint number = uint.Parse(Console.ReadLine());
        Console.WriteLine((number & 8) >> 3);
    }
}