using System;
using System.Collections.Generic;

public delegate bool MyDelegate(int n);

public class Program
{
    public static List<int> Filtru(MyDelegate conditie, List<int> lista)
    {
        List<int> rezultat = new List<int>();
        foreach(int element in lista)
        {
            if(conditie(element))
                rezultat.Add(element);
        }
        return rezultat;
    }

    public static bool EstePar(int x)
    {
        return x % 2 == 0;
    }

    static void Main(string[] args)
    {
        List<int> numere = new List<int> {1, 2, 3, 4, 5, 6, 7, 8};
        MyDelegate del = EstePar;

        List<int> filtrare = Filtru(del, numere);

        Console.WriteLine("Lista cu numere pare: " + string.Join(", ", filtrare));
    }
}