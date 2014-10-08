using System;

class DecToHex
{
    static void Main()
    {
        long dec = long.Parse(Console.ReadLine());
        string hex = string.Empty;
        while(dec > 0)
        {
            switch(dec % 16)
            {
                case 10:
                    hex = 'A' + hex;
                    break;
                case 11:
                    hex = 'B' + hex;
                    break;
                case 12:
                    hex = 'C' + hex;
                    break;
                case 13:
                    hex = 'D' + hex;
                    break;
                case 14:
                    hex = 'E' + hex;
                    break;
                case 15:
                    hex = 'F' + hex;
                    break;
                default:
                    hex = (dec % 10).ToString() + hex;
                    break;
            }
            dec /= 16;
        }
        Console.WriteLine(hex);
    }
}