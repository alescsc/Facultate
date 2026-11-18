using System;
using System.Collections.Generic;

public enum TipCont
{
    Persoana,
    Companie
}

public class Cont
{
    public string Titular { get; }
    public TipCont Tip { get; }
    public string Iban { get; }
    public double Suma { get; private set; }

    public Cont(string titular, TipCont tip, string iban, double suma)
    {
        Titular = titular;
        Tip = tip;
        Iban = iban;
        Suma = suma;
    }

    public bool Depunere(double suma)
    {
        if (suma <= 0)
        {
            Console.WriteLine("Nu se poate depune o suma negativa sau nula!");
            return false;
        }

        Suma += suma;
        Console.WriteLine($"Ati depus {suma} RON. Aveti: {Suma} RON");
        return true;
    }

    public bool Retragere(double suma)
    {
        if (suma <= 0)
        {
            Console.WriteLine("Nu se poate retrage o suma negativa sau nula!");
            return false;
        }

        if (Suma < suma)
        {
            Console.WriteLine($"Nu aveti bani suficienti in cont! Fonduri: {Suma}");
            return false;
        }

        Suma -= suma;
        Console.WriteLine($"Ati extras {suma} RON. Mai aveti: {Suma} RON");
        return true;
    }

    public override string ToString()
    {
        return $"Titular: {Titular}, Tip: {Tip}, Iban: {Iban}, Suma: {Suma}";
    }
}   

public class Banca
{
    public string Nume { get; }
    public string Swift { get; }
    public List<Cont> Lista { get; } = new List<Cont>();

    public Banca(string nume, string swift)
    {
        Nume = nume;
        Swift = swift;
    }

    private Cont? GetAccount(string iban)
    {
        for (int i = 0; i < Lista.Count; i++)
        {
            if (Lista[i].Iban == iban)
                return Lista[i];
        }
        return null;
    }

    public void DeschidereCont(string titular, TipCont tip, string iban, double suma)
    {
        if (GetAccount(iban) != null)
        {
            Console.WriteLine("Contul acesta deja exista!");
        }
        else
        {
            Lista.Add(new Cont(titular, tip, iban, suma));
            Console.WriteLine("Cont deschis cu succes!");
        }
    }

    public void GasireCont(string iban)
    {
        Cont? cont = GetAccount(iban);
        if (cont == null)
            Console.WriteLine($"Contul cu iban-ul {iban} nu exista!");
        else
            Console.WriteLine(cont);
    }

    public void DepunereCont(string iban, double suma)
    {
        Cont? cont = GetAccount(iban);
        if (cont == null)
            Console.WriteLine($"Contul cu iban-ul {iban} nu exista!");
        else
            cont.Depunere(suma);
    }

    public void RetragereCont(string iban, double suma)
    {
        Cont? cont = GetAccount(iban);
        if (cont == null)
            Console.WriteLine($"Contul cu iban-ul {iban} nu exista!");
        else
            cont.Retragere(suma);
    }

    public void Transfer(string iban1, string iban2, double suma)
    {
        Cont? c1 = GetAccount(iban1);
        Cont? c2 = GetAccount(iban2);

        if (c1 == null)
            Console.WriteLine($"Contul cu iban-ul {iban1} nu exista!");
        else if (c2 == null)
            Console.WriteLine($"Contul cu iban-ul {iban2} nu exista!");
        else if (c1.Retragere(suma))
            c2.Depunere(suma);
    }
}

class Program
{
    static void Main(string[] args)
    {
        Banca banca = new Banca("Banca Transilvania", "BTRLRO22");

        banca.DeschidereCont("Ion Popescu", TipCont.Persoana, "RO01BTRL0001", 1000);
        banca.DeschidereCont("SC Soft SRL", TipCont.Companie, "RO02BTRL0002", 5000);

        banca.GasireCont("RO01BTRL0001");
        banca.DepunereCont("RO01BTRL0001", 250);
        banca.RetragereCont("RO02BTRL0002", 10000);   // esueaza
        banca.Transfer("RO02BTRL0002", "RO01BTRL0001", 1500);
        banca.GasireCont("RO99XXXX9999");             // nu exista
    }
}