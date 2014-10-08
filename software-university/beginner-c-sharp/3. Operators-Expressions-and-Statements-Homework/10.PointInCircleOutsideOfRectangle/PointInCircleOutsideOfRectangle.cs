using System;

class PointInCircleOutsideOfRectangle
{
    static bool isInCircle(double x, double y)
    {
        double distanceToCenter = Math.Sqrt((x - 1) * (x - 1) + (y - 1) * (y - 1));
        return distanceToCenter <= 1.5;
    }
    static bool isInRectangle(double x, double y)
    {
        return (x >= -1 && x <= 5) && (y >= -1 && y <= 1);
    }
    static void Main()
    {
        double x = double.Parse(Console.ReadLine());
        double y = double.Parse(Console.ReadLine());
        Console.WriteLine(isInCircle(x, y) && !isInRectangle(x, y));
    }
}