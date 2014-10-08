using System;

class PrintSequence
{
    static void Main()
    {
        const int N = 1000;
        for (int i = 2; i < N + 1; i++)
        {
            if (i % 2 == 1) Console.Write("-");
            Console.Write("{0}, ", i);
        }
        if ((N + 1) % 2 == 1) Console.WriteLine("-{0}", N + 1);
        else Console.WriteLine("{0}", N + 1);
    }
}