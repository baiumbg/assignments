using System;

class DecToBin
{
    static void Main()
    {
        long number = long.Parse(Console.ReadLine());
        string result = string.Empty;
        while(number > 0)
        {
            result = (number % 2).ToString() + result;
            number /= 2;
        }
        Console.WriteLine(result);
    }
}