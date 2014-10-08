using System;

class AdvancedBitSwap
{
    static int getBitValue(uint number, int position)
    {
        return (int)((number & (1 << position)) >> position);
    }

    static void Main()
    {
        uint number;
        int p, q, k;
        try
        {
            number = uint.Parse(Console.ReadLine());
            p = int.Parse(Console.ReadLine());
            q = int.Parse(Console.ReadLine());
            k = int.Parse(Console.ReadLine());
        }
        catch (System.OverflowException e)
        {
            Console.WriteLine("out of range");
            return;
        }
        if (p > q)
        {
            int temp = p;
            p = q;
            q = temp;
        }
        if (q - p < k)
        {
            Console.WriteLine("overlapping");
        }
        else if (p + k > 31 || q + k > 31 || p < 0 || q < 0)
        {
            Console.WriteLine("out of range");
        }
        else
        {
            for (int i = 0; i < k; i++)
            {
                if (getBitValue(number, i + p) != getBitValue(number, i + q))
                {
                    number ^= (uint)(1 << i + p);
                    number ^= (uint)(1 << i + q);
                }
            }
            Console.WriteLine(number);
        }
    }
}