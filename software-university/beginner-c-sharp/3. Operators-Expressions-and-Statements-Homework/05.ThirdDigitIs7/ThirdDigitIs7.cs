using System;

class ThirdDigitIs7
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        Console.WriteLine((n/100)%10==7);
    }
}
