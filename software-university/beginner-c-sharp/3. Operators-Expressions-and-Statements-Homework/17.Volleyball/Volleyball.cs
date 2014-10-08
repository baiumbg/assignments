using System;

class Volleyball
{
    static void Main()
    {
        string typeOfYear = Console.ReadLine();
        int numberOfHolidays = int.Parse(Console.ReadLine());
        int hometownWeekends = int.Parse(Console.ReadLine());
        double totalPlays = hometownWeekends + 3 * (48 - hometownWeekends) / 4D + 2 * numberOfHolidays / 3D;
        if (typeOfYear == "leap") totalPlays *= 1.15D;
        Console.WriteLine((int)totalPlays);
    }
}