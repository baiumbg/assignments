using System;

class IsoscelesTriangle
{
    static void Main()
    {
        //Console.OutputEncoding = System.Text.Encoding.UTF8;
        char copyright = '\u00A9';
        Console.WriteLine("{0,4}", copyright);
        Console.WriteLine("{0,3}{1,2}", copyright, copyright);
        Console.WriteLine("{0,2}{1,4}", copyright, copyright);
        Console.WriteLine("{0} {1} {2} {3}", copyright, copyright, copyright, copyright);
    }
}
