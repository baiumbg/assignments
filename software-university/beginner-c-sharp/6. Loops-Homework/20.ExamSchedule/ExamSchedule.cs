using System;

class ExamSchedule
{
    static void Main()
    {
        DateTime start = DateTime.Parse(Console.ReadLine() + ':' + Console.ReadLine() + ' ' + Console.ReadLine());
        start = start.AddHours(int.Parse(Console.ReadLine()));
        start = start.AddMinutes(int.Parse(Console.ReadLine()));
        string output = string.Empty;
        if (start.Hour > 12)
        {
            output = string.Format("{0:D2}:{1:D2}:{2}", start.Hour - 12, start.Minute, "PM");
        }
        else if (start.Hour == 0)
        {
            output = string.Format("12:{0:D2}:AM", start.Minute);
        }
        else if(start.Hour == 12)
        {
            output = string.Format("12:{0:D2}:PM", start.Minute);
        }
        else output = string.Format("{0:D2}:{1:D2}:{2}", start.Hour, start.Minute, "AM");
        Console.WriteLine(output);
    }
}