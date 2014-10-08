using System;

class BinToDec
{
    static void Main()
    {
        string binary = Console.ReadLine();
        long dec = 0;
        for (int i = binary.Length - 1, step = 0; i >= 0; i--, step++)
        {
            dec += (long)((int.Parse(binary[i].ToString())) * Math.Pow(2, step));
        }
        Console.WriteLine(dec);
    }
}