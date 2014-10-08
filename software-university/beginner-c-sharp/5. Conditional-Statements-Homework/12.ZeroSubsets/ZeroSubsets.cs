using System;
using System.Linq;

class ZeroSubsets
{
    static void Main()
    {

        //Assuming that repeating the same subset several times is not a problem.

        string input;
        int[] numbers = new int[5];
        bool foundZeroSubset = false;

        input = Console.ReadLine();
        if (int.TryParse(input, out numbers[0]))
            for (int i = 1; i < 5; i++)
                numbers[i] = int.Parse(Console.ReadLine());
        else
            for (int i = 0; i < 5; i++)
                numbers[i] = int.Parse(input.Split()[i]);

        for (int i = 0; i < 4; i++)
            for (int j = i + 1; j < 5; j++)
                if (numbers[i] + numbers[j] == 0)
                {
                    Console.WriteLine("{0} + {1} = 0", numbers[i], numbers[j]);
                    foundZeroSubset = true;
                }

        for (int i = 0; i < 3; i++)
            for (int j = i + 1; j < 4; j++)
                for (int k = j + 1; k < 5; k++)
                    if (numbers[i] + numbers[j] + numbers[k] == 0)
                    {
                        Console.WriteLine("{0} + {1} + {2} = 0", numbers[i], numbers[j], numbers[k]);
                        foundZeroSubset = true;
                    }

        for (int i = 0; i < 2; i++)
            for (int j = i + 1; j < 3; j++)
                for (int k = j + 1; k < 4; k++)
                    for (int l = k + 1; l < 5; l++)
                        if (numbers[i] + numbers[j] + numbers[k] + numbers[l] == 0)
                        {
                            Console.WriteLine("{0} + {1} + {2} + {3} = 0", numbers[i], numbers[j], numbers[k], numbers[l]);
                            foundZeroSubset = true;
                        }

        if (numbers.Sum() == 0)
        {
            for (int i = 0; i < 4; i++)
                Console.Write("{0} + ", numbers[i]);
            Console.WriteLine("{0} = 0", numbers[4]);
            foundZeroSubset = true;
        }

        if (!foundZeroSubset) Console.WriteLine("no zero subsets");

    }
}
