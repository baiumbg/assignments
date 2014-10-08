using System;

class WeightOnTheMoon
{
    static void Main()
    {
        float weight = float.Parse(Console.ReadLine());
        float newWeight = 17 * weight / 100;
        Console.WriteLine(newWeight);
    }
}