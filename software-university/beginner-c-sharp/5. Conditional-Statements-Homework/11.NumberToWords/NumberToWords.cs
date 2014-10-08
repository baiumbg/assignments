using System;

class NumberToWords
{
    static void Main()
    {
        string[] units = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
        string[] tens = { "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
        int number = int.Parse(Console.ReadLine());
        string words = "";

        if (number / 100 > 0) words += units[number / 100] + " hundred";

        if ((number / 10) % 10 == 1)
        {
            if (number > 100) words += " and ";
            words += units[((number / 10) % 10) + (number % 10) + 9];
        }
        else if ((number / 10) % 10 > 1)
        {
            if (number > 100) words += " and ";
            words += tens[(number / 10) % 10 - 1];
        }

        if (number % 10 > 0 && (number / 10) % 10 != 1)
        {
            if ((number / 10) % 10 == 0) words += " and ";
            else if (number > 10) words += ' ';
            words += units[number % 10];
        }

        if (number == 0) words = "zero";

        Console.WriteLine(words);
    }
}