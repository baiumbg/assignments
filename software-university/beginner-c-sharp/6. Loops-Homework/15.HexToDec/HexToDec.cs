using System;

class HexToDec
{
    static void Main()
    {
        string hex = Console.ReadLine();
        long dec = 0L;
        for (int i = hex.Length - 1, step = 0; i >= 0; i--, step++)
        {
            switch (hex[i])
            {
                case 'A':
                    dec += 10L * (long)Math.Pow(16, step);
                    break;
                case 'B':
                    dec += 11L * (long)Math.Pow(16, step);
                    break;
                case 'C':
                    dec += 12L * (long)Math.Pow(16, step);
                    break;
                case 'D':
                    dec += 13L * (long)Math.Pow(16, step);
                    break;
                case 'E':
                    dec += 14L * (long)Math.Pow(16, step);
                    break;
                case 'F':
                    dec += 15L * (long)Math.Pow(16, step);
                    break;
                default:
                    dec += int.Parse(hex[i].ToString()) * (long)Math.Pow(16, step);
                    break;
            }
        }
        Console.WriteLine(dec);
    }
}