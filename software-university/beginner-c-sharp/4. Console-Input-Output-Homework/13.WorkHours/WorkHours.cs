using System;

class WorkHours
{
    static void Main()
    {
        int requiredHours, daysAvailable, productivity;
        requiredHours = int.Parse(Console.ReadLine());
        daysAvailable = int.Parse(Console.ReadLine());
        productivity = int.Parse(Console.ReadLine());
        double totalHoursWorked = Math.Floor(12d * daysAvailable * 0.9d * (productivity/100d));
        Console.WriteLine(totalHoursWorked >= requiredHours ? "Yes" : "No");
        Console.WriteLine(totalHoursWorked - requiredHours);
    }
}