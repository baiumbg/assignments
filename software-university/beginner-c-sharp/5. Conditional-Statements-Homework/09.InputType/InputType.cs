using System;

class InputType
{
    static void Main()
    {
        int type = int.Parse(Console.ReadLine());
        switch(type)
        {
            case 1:
            {
                int number = int.Parse(Console.ReadLine()) + 1;
                Console.WriteLine(number);
                break;
            }
            case 2:
            {
                double number = double.Parse(Console.ReadLine()) + 1d;
                Console.WriteLine(number);
                break;
            }
            case 3:
            {
                string s = Console.ReadLine() + '*';
                Console.WriteLine(s);
                break;
            }
        }
    }
}