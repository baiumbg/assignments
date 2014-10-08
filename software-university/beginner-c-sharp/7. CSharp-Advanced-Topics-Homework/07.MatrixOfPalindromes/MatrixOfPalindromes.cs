using System;

class MatrixOfPalindromes
{
    static void Main()
    {
        int rows = int.Parse(Console.ReadLine());
        int columns = int.Parse(Console.ReadLine());
        string[,] palindromes = new string[rows, columns];
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                palindromes[i, j] = new string((char)('a' + i), 3);
                char[] tmp = palindromes[i, j].ToCharArray();
                tmp[1] = (char)('a' + i + j);
                palindromes[i, j] = new string(tmp);
            }
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                Console.Write("{0} ", palindromes[i, j]);
            }
            Console.WriteLine();
        }
    }
}