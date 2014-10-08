using System;

class LongestWord
{
    static void Main()
    {
        string input = Console.ReadLine();

        string[] words = input.Split(new char[] {' ', '.', '?', '!', ','}, StringSplitOptions.RemoveEmptyEntries);
        string longestWord = string.Empty;

        foreach(var word in words)
        {
            if (word.Length > longestWord.Length) longestWord = word;
        }

        Console.WriteLine(longestWord);
    }
}