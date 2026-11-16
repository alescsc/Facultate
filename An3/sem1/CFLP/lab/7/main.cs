using System;
using System.Collections.Generic;

public class CititorIntrare
{
    public event EventHandler<string> OnKeyPressed;

    public void ReadKeys()
    {
        Console.WriteLine("Introduceti siruri: ");
        while(true)
        {
            string linie = Console.ReadLine();
            if(string.IsNullOrEmpty(linie))
            {
                break;
            }
            if(OnKeyPressed != null)
            {
                OnKeyPressed(this, linie);
            }
        }
    }
}

public class AscultatorCaracter
{
    private char caracterCautat;

    public AscultatorCaracter(char c, CititorIntrare cititor)
    {
        caracterCautat = c;
        cititor.OnKeyPressed += HandleKeyPressed;
    }

    public void HandleKeyPressed(object sender, string sir)
    {
        if(sir.IndexOf(caracterCautat) != -1)
        {
            Console.WriteLine($"Caracterul '{caracterCautat}' a fost gasit in sirul: \"{sir}\"");
        }
    }
}

public class AscultatorComplex
{
    private int strNo;
    private List<string> istoricSiruri;

    public AscultatorComplex(int strNo, CititorIntrare cititor)
    {
        this.strNo = strNo;
        istoricSiruri = new List<string>();
        cititor.OnKeyPressed += HandleKeyPressed;
    }
    public void HandleKeyPressed(object sender, string sir)
    {
        if(sir == "afiseaza ultimul")
        {
           if(istoricSiruri.Count > 0)
            {
                Console.WriteLine("Ultimul element: " + istoricSiruri[istoricSiruri.Count - 1]);
            }
            else
            {
                Console.WriteLine("Ultimul element: Linia este goala");
            }
            return;
        }

        if(sir == "afiseaza toate")
        {
            Console.WriteLine("Toate elementele salvate:");
            foreach(string item in istoricSiruri)
            {
                Console.WriteLine(" - " + item);
            }
            return;
        }

        if(istoricSiruri.Count == strNo)
        {
            istoricSiruri.RemoveAt(0);
        }
        istoricSiruri.Add(sir);
    }
}

public class Program
{
    static void Main(string[] args)
    {
        CititorIntrare cititor = new CititorIntrare();

        AscultatorCaracter asc1 = new AscultatorCaracter('a', cititor);
        AscultatorCaracter asc2 = new AscultatorCaracter('z', cititor);
        AscultatorComplex ascComplex = new AscultatorComplex(3, cititor);

        cititor.ReadKeys();
    }
}
