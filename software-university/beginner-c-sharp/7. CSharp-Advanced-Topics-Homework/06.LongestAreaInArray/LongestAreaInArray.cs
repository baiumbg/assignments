using System;

class LongestAreaInArray
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        string[] s = new string[n];
        for (int i = 0; i < n; i++)
        {
            s[i] = Console.ReadLine();
        }
        string currString = string.Empty;
        int currLenght = 1;
        int maxLenght = 1;
        string maxString = s[0];
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n && s[i] == s[j]; j++)
            {
                currLenght++;
                currString = s[j];
            }
            if (currLenght > maxLenght)
            {
                maxLenght = currLenght;
                maxString = currString;
            }
            currLenght = 1;
        }
        Console.WriteLine(maxLenght);
        for (int i = 0; i < maxLenght; i++)
        {
            Console.WriteLine(maxString);
        }
    }
}