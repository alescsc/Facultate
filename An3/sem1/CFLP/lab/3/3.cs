using System;

public class Cont
{
    public string Nume {get; private set;}
    public double Sold {get; private set;}

    public Cont(string nume, double sold)
    {
        Nume = nume;
        Sold = sold;
    }

    public bool Retragere(double suma, out double soldRamas)
    {
        if(suma <= Sold && suma > 0)
        {
            Sold = Sold - suma;
            soldRamas = Sold;
            return true;
        }
        else
        {
            soldRamas = Sold;
            return false;
        }
    }
}

public class Program
{
    static void Main(string[] args)
    {
        Cont cont = new Cont("Ion Popescu", 1500.0);
        Console.WriteLine($"Sold initial: {cont.Sold}");
        double rest;
        bool succes = cont.Retragere(2000.0, out rest);
        if(succes)
        {
            Console.WriteLine($"Retragere reusita! Sold: {rest} RON");
        }
        else
        {
            Console.WriteLine($"Fonduri insuficiente!");
        }

        bool succes2 = cont.Retragere(100.0, out rest);
        if(succes2)
        {
            Console.WriteLine($"Retragere reusita! Sold: {rest} RON");
        }
        else
        {
            Console.WriteLine($"Fonduri insuficiente!");
        }
    }
}