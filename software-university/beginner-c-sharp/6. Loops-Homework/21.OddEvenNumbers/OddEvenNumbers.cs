using System;

class OddEvenNumbers
{
    static void Main()
    {
        System.Threading.Thread.CurrentThread.CurrentCulture = System.Globalization.CultureInfo.InvariantCulture;
        string input = Console.ReadLine();
        string[] rawNumbers = input.Split();
        if (input == "")
        {
            rawNumbers = new string[0];
        }
        decimal oddSum = 0, oddMin, oddMax, evenSum = 0, evenMin, evenMax;
        if (rawNumbers.Length == 1)
        {
            Console.WriteLine("OddSum={0:G29}, OddMin={0:G29}, OddMax={0:G29}, EvenSum=No, EvenMin=No, EvenMax=No", rawNumbers[0]);
            return;
        }
        if (rawNumbers.Length == 0)
        {
            Console.WriteLine("OddSum=No, OddMin=No, OddMax=No, EvenSum=No, EvenMin=No, EvenMax=No");
            return;
        }
        decimal[] numbers = new decimal[rawNumbers.Length];
        for (int i = 0; i < rawNumbers.Length; i++)
        {
            numbers[i] = decimal.Parse(rawNumbers[i]);
        }
        oddMin = numbers[0];
        oddMax = numbers[0];
        evenMin = numbers[1];
        evenMax = numbers[1];
        for (int i = 0; i < numbers.Length; i++)
        {
            if (i % 2 == 0)
            {
                oddSum += numbers[i];
                if (numbers[i] < oddMin) oddMin = numbers[i];
                if (numbers[i] > oddMax) oddMax = numbers[i];
            }
            else
            {
                evenSum += numbers[i];
                if (numbers[i] < evenMin) evenMin = numbers[i];
                if (numbers[i] > evenMax) evenMax = numbers[i];
            }
        }
        Console.WriteLine("OddSum={0:G29}, OddMin={1:G29}, OddMax={2:G29}, EvenSum={3:G29}, EvenMin={4:G29}, EvenMax={5:G29}", oddSum, oddMin, oddMax, evenSum, evenMin, evenMax);
    }
}