using System;
using System.Collections.Generic;

class ExtractURLs
{
    static void Main()
    {

        string[] input = Console.ReadLine().Split();
        List<string> URLs = new List<string>();

        foreach(var item in input)
        {
            if(item.StartsWith("http://") || item.StartsWith("www."))
            {
                string entry = item.Trim('.', ',', '!', '?');
                if (!URLs.Contains(entry)) URLs.Add(entry);
            }
        }

        foreach(var URL in URLs)
        {
            Console.WriteLine(URL);
        }

    }
}