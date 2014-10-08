using System;

class TheExplorer
{
    static string symbols(int numberOfTimes, char symbol)
    {
        return new string(symbol, numberOfTimes);
    }

    static void Main()
    {
        int width = int.Parse(Console.ReadLine());
        for (int i = 0; i < width; i++)
        {
            if(i == 0 || i == width-1)
                Console.WriteLine("{0}*{1}", symbols((width - 1) / 2, '-'), symbols((width - 1) / 2, '-'));
            else if(i < width/2 + 1)
                Console.WriteLine("{0}*{1}*{2}", symbols(width / 2 - i, '-'), symbols(2 * i - 1, '-'), symbols(width / 2 - i, '-'));
            else if(i >= width/2 + 1)
                Console.WriteLine("{0}*{1}*{2}", symbols(i - (width / 2), '-'), symbols(width - 2 * (i - width / 2 + 1), '-'), symbols(i - (width/2), '-'));
        }
    }
}