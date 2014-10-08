using System;

class Arrow
{
    static string stringFromChar(int size, char c)
    {
        return new string(c, size);
    }
    static void Main()
    {
        int N = int.Parse(Console.ReadLine());
        int totalSize = 2 * N - 1;
        Console.WriteLine("{0}#{1}#{0}", stringFromChar((totalSize - N)/2, '.'), stringFromChar(N - 2, '#'));
        for (int i = 1; i < totalSize - 1; i++)
        {
            if (i < totalSize / 2)
            {
                Console.WriteLine("{0}#{1}#{0}", stringFromChar((totalSize - N)/2, '.'), stringFromChar(N - 2, '.'));
            }
            else if (i == totalSize / 2)
            {
                Console.WriteLine("{0}#{1}#{0}", stringFromChar((totalSize - N)/2, '#'), stringFromChar(N - 2, '.'));
            }
            else
            {
                Console.WriteLine("{0}#{1}#{0}", stringFromChar(i - totalSize / 2, '.'), stringFromChar(2 * totalSize - 2 * i - 3, '.'));
            }
        }
        Console.WriteLine("{0}#{0}", stringFromChar((totalSize-1)/2, '.'));
    }
}