using System;

class PrintCompanyInformation
{
    static void Main()
    {
        string name, address, phoneNumber, faxNumber, website, managerFirstName, managerLastName, managerAge, managerPhone;
        Console.Write("Company name: ");
        name = Console.ReadLine();

        Console.Write("Company address: ");
        address = Console.ReadLine();

        Console.Write("Phone number: ");
        phoneNumber = Console.ReadLine();

        Console.Write("Fax number: ");
        faxNumber = Console.ReadLine();

        Console.Write("Website: ");
        website = Console.ReadLine();

        Console.Write("Manager first name: ");
        managerFirstName = Console.ReadLine();

        Console.Write("Manager last name: ");
        managerLastName = Console.ReadLine();

        Console.Write("Manager age: ");
        managerAge = Console.ReadLine();

        Console.Write("manager phone: ");
        managerPhone = Console.ReadLine();

        Console.WriteLine();
        Console.WriteLine(name);
        Console.WriteLine("Address: {0}", address != "" ? address : "(no address)");
        Console.WriteLine("Tel. {0}", phoneNumber != "" ? phoneNumber : "(no phone number)");
        Console.WriteLine("Fax: {0}", faxNumber != "" ? faxNumber : "(no fax)");
        Console.WriteLine("Website: {0}", website != "" ? website : "(no website)");
        Console.WriteLine("Manager: {0} {1} (age: {2}, tel. {3})", managerFirstName, managerLastName, managerAge, managerPhone);
    }
}