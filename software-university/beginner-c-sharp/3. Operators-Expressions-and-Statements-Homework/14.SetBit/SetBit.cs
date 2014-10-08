using System;

class SetBit
{
    static void Main()
    {
        int number = int.Parse(Console.ReadLine());
        int position = int.Parse(Console.ReadLine());
        byte bit = byte.Parse(Console.ReadLine());
        //check if requested bit and new bit value are different
        if ((number & (1 << position)) != 0 && bit == 0 || ((number & (1 << position)) == 0 && bit == 1))
        {
            number ^= (1 << position); //toggle bit
        }
        Console.WriteLine(number);
    }
}