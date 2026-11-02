using System;
using System.Collections.Generic;

public interface IRentable
{
    bool IsRented { get; set; }
    double MonthlyRent { get; set; }
}

public abstract class Property
{
    public string Address { get; set; }
    public double IndoorArea { get; set; }
    public double PropertyValue { get; set; }

    public Property(string address, double indoorArea, double propertyValue)
    {
        Address = address;
        IndoorArea = indoorArea;
        PropertyValue = propertyValue;
    }

    public override string ToString()
    {
        return $"Adresa: {Address}, Suprafata interioara: {IndoorArea}mp, Pret: {PropertyValue} EUR";
    }
}

public class House : Property
{
    public double OutdoorArea { get; set; }
    public double TotalArea => IndoorArea + OutdoorArea;

    public House(string address, double indoorArea, double propertyValue, double outdoorArea)
        : base(address, indoorArea, propertyValue)
    {
        OutdoorArea = outdoorArea;
    }

    public override string ToString()
    {
        return $"[Casa] {base.ToString()}, Suprafata exterioara: {OutdoorArea}mp, Suprafata totala: {TotalArea}mp";
    }
}

public class Apartment : Property
{
    public int Floor { get; set; }
    public bool HasElevator { get; set; }

    public Apartment(string address, double indoorArea, double propertyValue, int floor, bool hasElevator)
        : base(address, indoorArea, propertyValue)
    {
        Floor = floor;
        HasElevator = hasElevator;
    }

    public override string ToString()
    {
        return $"[Apartament] {base.ToString()}, Etaj: {Floor}, Lift: {HasElevator}";
    }
}

public class RentableApartment : Apartment, IRentable
{
    public bool IsRented { get; set; }
    public double MonthlyRent { get; set; }

    public RentableApartment(string address, double indoorArea, double propertyValue, int floor, bool hasElevator, bool isRented, double monthlyRent)
        : base(address, indoorArea, propertyValue, floor, hasElevator)
    {
        IsRented = isRented;
        MonthlyRent = monthlyRent;
    }

    public override string ToString()
    {
        return base.ToString() + $" | Chirie lunara: {MonthlyRent} EUR, Status: {IsRented}";
    }
}

public class RealEstateAgency
{
    public List<Property> Properties { get; private set; }

    public RealEstateAgency()
    {
        Properties = new List<Property>();
    }

    public void AddProperty(Property property)
    {
        Properties.Add(property);
        Console.WriteLine($"Adaugata cu succes in agentie! -> {property}");
    }

    public void RentProperty(string address)
    {
        Property found = null;
        foreach(var p in Properties)
        {
            if(p.Address.ToLower() == address.ToLower())
            {
                found = p;
                break;
            }
        }
        if(found == null)
        {
            Console.WriteLine($"Eroare: Adresa {address} nu a fost gasita!");
            return;
        }

        IRentable propRentable = found as IRentable;
        if(propRentable == null)
        {
            Console.WriteLine($"Propietatea de la adresa {address} nu poate fi inchiriata!");
            return;
        }
        if(propRentable.IsRented == true)
        {
            Console.WriteLine($"Propietatea de la adresa {address} este deja inchiriata!");
        }
        else
        {
            propRentable.IsRented = true;
            Console.WriteLine($"Succes! Propietatea de la adresa {address} a fost inchiriata! Chirie: {propRentable.MonthlyRent} EUR/month");
        }
    }
}

public class Program
{
    static void Main(string[] args)
    {
        RealEstateAgency ag = new RealEstateAgency();

        House h = new House("Str. Campului 12", 100, 120000, 250);
        Apartment a = new Apartment("Bulevardul Eroilor 4", 55, 70000, 2, true);
        RentableApartment ra = new RentableApartment("Aleea Lalelelor 6", 45, 55000, 4, false, false, 350);

        ag.AddProperty(h);
        ag.AddProperty(a);
        ag.AddProperty(ra);

        Console.WriteLine();
        ag.RentProperty("Aleea Lalelelor 6");
        ag.RentProperty("Aleea Lalelelor 6");
        ag.RentProperty("Str. Ineu 1");
        ag.RentProperty("Str. Campului 12");
    }
}
