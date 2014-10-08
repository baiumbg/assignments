using System;

class JoroTheFootballPlayer
{
    static void Main()
    {
        string typeOfYear;
        int totalPlays, numberOfHolidays, hometownWeekends;
        typeOfYear = Console.ReadLine();
        numberOfHolidays = int.Parse(Console.ReadLine());
        hometownWeekends = int.Parse(Console.ReadLine());
        totalPlays = numberOfHolidays / 2 + hometownWeekends + 2 * (52 - hometownWeekends) / 3;
        if (typeOfYear == "t") totalPlays += 3;
        Console.Write(totalPlays);
    }
}