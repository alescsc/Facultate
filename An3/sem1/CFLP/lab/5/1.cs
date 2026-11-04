using System;

public class Program
{
    public static void RemoveAt(int[] array, ref int length, int n)
    {
        if(n < 0 || n >= length)
            return;
        for(int i = n; i < length - 1; i++)
            array[i] = array[i + 1];
        length--;
    }

    static void Main(string[] args)
    {
        int[] numere = {10, 20, 30, 40, 50};
        int lungime = 5;
        RemoveAt(numere, ref lungime, 2);
        Console.Write("Dupa stergere: ");
        for(int i = 0; i < lungime; i++)
            Console.Write(numere[i] + " ");
    }
}