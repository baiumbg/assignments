using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;

class AverageLoadTime
{
    static void Main()
    {
        System.Threading.Thread.CurrentThread.CurrentCulture = System.Globalization.CultureInfo.InvariantCulture;

        StreamReader reportReader = new StreamReader("../../report.txt");
        string report = reportReader.ReadToEnd();
        string[] reportItems = report.Split(new char[] { '\n' }, StringSplitOptions.RemoveEmptyEntries);
        Dictionary<string, List<double>> urlDicionary = new Dictionary<string, List<double>>();

        foreach (var item in reportItems)
        {
            string url = item.Split()[2];
            double loadTime = double.Parse(item.Split()[3]);
            if (!urlDicionary.ContainsKey(url)) urlDicionary.Add(url, new List<double>());
            urlDicionary[url].Add(loadTime);
        }

        foreach(string url in urlDicionary.Keys)
        {
            double average = 0;
            foreach(var loadTime in urlDicionary[url])
            {
                average += loadTime;
            }
            average /= urlDicionary[url].Count;
            Console.WriteLine("{0} -> {1}", url, average);
        }

    }
}