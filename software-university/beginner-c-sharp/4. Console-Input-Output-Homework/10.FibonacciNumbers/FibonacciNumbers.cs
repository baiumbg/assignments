using System;

class FibonacciNumbers
{
    static int fibonacciNumber(int number)
    {
        int previousNumber = 0, currentNumber = 1;
        for (int i = 0; i < number - 1; i++)
        {
            int temp = previousNumber;
            previousNumber = currentNumber;
            currentNumber += temp;
        }
        return previousNumber;
    }
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        for (int i = 1; i <= n; i++)
        {
            Console.Write("{0} ", fibonacciNumber(i));
        }
        Console.WriteLine();
    }
}