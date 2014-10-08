using System;

class SpiralMatrix
{
    static void fillTopRight(int[,] arr, int x1, int y1, int x2, int y2, int number = 1)
    {
        for (int i = x1; i <= x2; i++)
        {
            arr[y1, i] = number;
            number++;
        }
        for (int j = y1 + 1; j <= y2; j++)
        {
            arr[j, x2] = number;
            number++;
        }
        if (x2 - x1 > 0)
        {
            fillBottomLeft(arr, x1, y1 + 1, x2 - 1, y2, number);
        }
    }
    static void fillBottomLeft(int[,] arr, int x1, int y1, int x2, int y2, int number)
    {
        for (int i = x2; i >= x1; i--)
        {
            arr[y2, i] = number;
            number++;
        }
        for (int j = y2 - 1; j >= y1; j--)
        {
            arr[j, x1] = number;
            number++;
        }
        if (x2 - x1 > 0)
        {
            fillTopRight(arr, x1 + 1, y1, x2, y2 - 1, number);
        }
    }
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[,] arr = new int[n, n];
        int spacesToPad = 2;
        fillTopRight(arr, 0, 0, n - 1, n - 1);
        if (n >= 4) spacesToPad++;
        if (n >= 10) spacesToPad++;
        for (int i = 0; i < arr.GetLength(0); i++)
        {
            for (int j = 0; j < arr.GetLength(1) - 1; j++)
            {
                Console.Write("{0}", arr[i, j].ToString().PadRight(spacesToPad));
            }
            Console.Write(arr[i, arr.GetLength(1) - 1]);
            Console.WriteLine();
        }
    }
}