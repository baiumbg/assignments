using System;

class SumOf5Numbers
{
    static void Main()
    {
        string[] numbers;
        double sum = 0;
        numbers = Console.ReadLine().Split();
        foreach(string number in numbers)
        {
            sum += double.Parse(number);
        }
        Console.WriteLine(sum);
    }
}