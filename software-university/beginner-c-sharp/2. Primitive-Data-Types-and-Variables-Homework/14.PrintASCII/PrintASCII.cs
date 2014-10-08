using System;

class PrintASCII
{
    static void Main()
    {
        for (int i = 0; i < 256; i++)
        {
            if (i != 255) Console.Write("{0}: {1}, ", i, (char)i);
            else Console.WriteLine("{0}: {1}", i, (char)i);
        }
    }
}