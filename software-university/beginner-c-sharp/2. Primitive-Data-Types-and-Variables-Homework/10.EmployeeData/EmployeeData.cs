using System;

class EmployeeData
{
    static void Main()
    {
        String firstName = "Veselin", lastName = "Dobrev";
        byte age = 18;
        char gender = 'm';
        long personalId = 9504136242L;
        int employeeId = 27564257;
        Console.WriteLine("First Name: {0}", firstName);
        Console.WriteLine("Last Name: {0}", lastName);
        Console.WriteLine("Age: {0}", age);
        Console.WriteLine("Gender: {0}", gender);
        Console.WriteLine("Personal ID number: {0}", personalId);
        Console.WriteLine("Unique Employee number: {0}", employeeId);
    }
}