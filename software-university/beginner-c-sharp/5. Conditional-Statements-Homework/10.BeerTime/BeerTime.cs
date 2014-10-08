using System;

class BeerTime
{
    static void Main()
    {
        DateTime t;
        if(DateTime.TryParse(Console.ReadLine(), out t))
        {
            //Console.WriteLine(t.ToString());
            if ((t.Hour >= 13 && t.Hour <= 24) || (t.Hour >= 0 && t.Hour < 3)) Console.WriteLine("beer time");
            else Console.WriteLine("non-beer time");
        }
        else Console.WriteLine("invalid time");
    }
}