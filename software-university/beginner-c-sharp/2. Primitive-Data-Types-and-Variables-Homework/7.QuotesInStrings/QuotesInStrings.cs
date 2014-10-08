using System;

class QuotesInStrings
{
    static void Main()
    {
        string v1 = @"The ""use"" of quotations causes difficulties.";
        string v2 = "The \"use\" of quotations causes difficulties.";
        Console.WriteLine("{0}\n{1}", v1, v2);
    }
}