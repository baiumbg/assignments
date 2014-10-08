using System;

class CountOfWord
{
    static void Main()
    {

        // Assuming the word we are looking for does not contain a special character.

        string word = Console.ReadLine();
        string[] words = Console.ReadLine().Split(new char[] {' ', '.', ',', '/', '\\', '\'', '!', '?', '@', ':', ';', '(', ')', '{', '}', '"'}, StringSplitOptions.RemoveEmptyEntries);
        int count = 0;

        foreach(var w in words)
        {
            if (w.ToLower() == word.ToLower()) count++;
        }

        Console.WriteLine(count);
    }
}