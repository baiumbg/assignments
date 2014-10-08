using System;

class StringsAndObjects
{
    static void Main()
    {
        string hello = "Hello", world = "World";
        object concatenated = hello + ' ' + world;
        string objectToString = (string)concatenated;
        Console.WriteLine(objectToString);
    }
}