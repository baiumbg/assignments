using System;

class OddAndEvenProduct
{
    static void Main()
    {
        string[] rawNumbers = Console.ReadLine().Split();
        int oddProduct = 1, evenProduct = 1;
        for (int i = 1; i <= rawNumbers.Length; i++)
        {
            if (i % 2 == 1) oddProduct *= int.Parse(rawNumbers[i - 1]);
            else evenProduct *= int.Parse(rawNumbers[i - 1]);
        }
        if (oddProduct == evenProduct) Console.WriteLine("yes\nproduct = {0}", evenProduct);
        else Console.WriteLine("no\nodd_product = {0}\neven_product = {1}", oddProduct, evenProduct);
    }
}