using System;
using System.Collections.Generic;

public class Program
{
    public static List<int> Intersection(List<int> l1, List<int> l2)
    {
        List<int> rezultat = new List<int>();
        foreach(int nr in l1)
        {
            if(l2.Contains(nr) && !rezultat.Contains(nr))
                rezultat.Add(nr);
        }
        return rezultat;
    }
    static void Main(string[] args)
    {
        List<int> lista1 = new List<int> {1, 2, 3, 2, 4};
        List<int> lista2 = new List<int> {2, 4, 6, 8};

        List<int> intersectie = Intersection(lista1, lista2);
        Console.WriteLine("Elemente comune: " + string.Join(" ", intersectie));
    }
}