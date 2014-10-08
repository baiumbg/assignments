using System;
using System.Globalization;

class Program
{
    static void Main()
    {
        NumberFormatInfo numberFormat = CultureInfo.InvariantCulture.NumberFormat;
        int Ax, Ay, Bx, By, Cx, Cy;

        Ax = int.Parse(Console.ReadLine());
        Ay = int.Parse(Console.ReadLine());
        Bx = int.Parse(Console.ReadLine());
        By = int.Parse(Console.ReadLine());
        Cx = int.Parse(Console.ReadLine());
        Cy = int.Parse(Console.ReadLine());

        double AB = Math.Sqrt((Bx - Ax) * (Bx - Ax) + (By - Ay) * (By - Ay));
        double AC = Math.Sqrt((Cx - Ax) * (Cx - Ax) + (Cy - Ay) * (Cy - Ay));
        double BC = Math.Sqrt((Cx - Bx) * (Cx - Bx) + (Cy - By) * (Cy - By));

        if (AB + AC > BC && AB + BC > AC && AC + BC > AB)
        {
            Console.WriteLine("Yes");
            double p = (AB + BC + AC) / 2d;
            double area = Math.Sqrt(p * (p - AB) * (p - AC) * (p - BC));
            Console.WriteLine(area.ToString("F2", numberFormat));
        }
        else
        {
            Console.WriteLine("No");
            Console.WriteLine(AB.ToString("F2", numberFormat));
        }
    }
}