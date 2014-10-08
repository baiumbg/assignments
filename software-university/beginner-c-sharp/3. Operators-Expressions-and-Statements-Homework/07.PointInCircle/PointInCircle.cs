using System;

class PointInCircle
{
    static void Main()
    {
        double x = double.Parse(Console.ReadLine());
        double y = double.Parse(Console.ReadLine());
        double distanceToCenter = Math.Sqrt(x*x + y*y);
        Console.WriteLine(distanceToCenter <= 2);
    }
}