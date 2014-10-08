using System;

class Sunglasses
{
    static string symbols(int numberOfTimes, char symbol)
    {
        return new string(symbol, numberOfTimes);
    }

    static void Main()
    {
        int heightOfGlasses = int.Parse(Console.ReadLine());
        for (int i = 0; i < heightOfGlasses; i++)
        {
            if (i == 0 || i == heightOfGlasses - 1)
                Console.WriteLine("{0}{1}{2}", symbols(2 * heightOfGlasses, '*'), symbols(heightOfGlasses, ' '), symbols(2 * heightOfGlasses, '*'));
            else if (i != heightOfGlasses / 2)
                Console.WriteLine("*{0}*{1}*{2}*", symbols(2 * heightOfGlasses - 2, '/'), symbols(heightOfGlasses, ' '), symbols(2 * heightOfGlasses - 2, '/'));
            else
                Console.WriteLine("*{0}*{1}*{2}*", symbols(2 * heightOfGlasses - 2, '/'), symbols(heightOfGlasses, '|'), symbols(2 * heightOfGlasses - 2, '/'));
        }
    }
}