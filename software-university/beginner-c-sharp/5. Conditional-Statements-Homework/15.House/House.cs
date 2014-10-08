using System;

class House
{

    static string stringFromChar(char c, int amount)
    {
        return new string(c, amount);
    }

    static void Main()
    {
        int N = int.Parse(Console.ReadLine());
        Console.WriteLine("{0}*{0}", stringFromChar('.', N / 2));
        for (int i = 1; i < N-1; i++)
        {
            if (i < N / 2)
            {
                Console.WriteLine("{0}*{1}*{0}", stringFromChar('.', (N / 2) - i), stringFromChar('.', (i - 1) * 2 + 1));
            }
            if (i == N / 2)
            {
                Console.WriteLine(stringFromChar('*', N));
            }
            if (i > N / 2)
            {
                Console.WriteLine("{0}*{1}*{0}", stringFromChar('.', N / 4), stringFromChar('.', N - (N / 4) - (N / 4) - 2));
            }
        }
        Console.WriteLine("{0}{1}{0}", stringFromChar('.', N / 4), stringFromChar('*', N - (N / 4) - (N / 4)));
    }
}