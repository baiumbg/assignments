using System;

class AgeAfter10Years
{
    static void Main()
    {
        DateTime now = DateTime.Now;
        DateTime birthday = DateTime.Parse(Console.ReadLine());
        int age = now.Subtract(birthday).Days/365;
        Console.WriteLine(age + 10);
    }
}