using System;

class GCD
{
    static void Main()
    {
        int a = int.Parse(Console.ReadLine());
        int b = int.Parse(Console.ReadLine());
        int GCD = 0;
        if(a > b)
        {
            int temp = a;
            a = b;
            b = temp;
        }
        while(b != 0)
        {
            GCD = a % b;
            a = b;
            if (GCD == 0)
            {
                GCD = b;
                b = 0;
            }
            else b = GCD;
        }
        Console.WriteLine(GCD);
    }
}