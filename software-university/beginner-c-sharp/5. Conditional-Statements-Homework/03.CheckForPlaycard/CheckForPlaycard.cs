using System;

class CheckForPlaycard
{
    static void Main()
    {
        string card = Console.ReadLine();
        int cardnumber;
        if(int.TryParse(card, out cardnumber))
        {
            if(cardnumber >= 2 && cardnumber <= 10) Console.WriteLine("Yes");
            else Console.WriteLine("No");
        }
        else switch (card)
        {
            case "K":
                {
                    Console.WriteLine("Yes");
                    break;
                }
            case "Q":
                {
                    Console.WriteLine("Yes");
                    break;
                }
            case "J":
                {
                    Console.WriteLine("Yes");
                    break;
                }
            case "A":
                {
                    Console.WriteLine("Yes");
                    break;
                }
            default:
                {
                    Console.WriteLine("No");
                    break;
                }
        }
    }
}