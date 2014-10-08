using System;

class BitSwap
{
    static int getBitValue(uint number, int position)
    {
        return (int)((number & (1 << position)) >> position);
    }

    static void Main()
    {
        uint number = uint.Parse(Console.ReadLine());
        for (int i = 0; i < 3; i++)
        {
            if (getBitValue(number, i + 3) != getBitValue(number, i + 24))
            {
                number ^= (uint)(1 << i + 3);
                number ^= (uint)(1 << i + 24);
            }
        }
        Console.WriteLine(number);
    }
}