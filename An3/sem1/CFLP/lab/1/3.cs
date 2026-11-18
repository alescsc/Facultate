using System;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.InteropServices.Marshalling;

public class Student
{
    public string nume {get;}
    public int an {get;}
    public double n1{get;}
    public double n2{get;}
    public double n3{get;}

    public Student(string Nume, int An, double N1, double N2, double N3)
    {
        nume = Nume;
        an = An;
        n1 = N1;
        n2 = N2;
        n3 = N3;
    }

    public double Medie
    {
        get { return (n1 + n2 + n3)/3.0; }
    }

    public override string ToString()
    {
        return $"Nume: {nume}, An: {an}, Nota 1: {n1}, Nota 2: {n2}, Nota 3: {n3}, Medie : {Medie}";
    }
}

public class Program 
{
    public static void Main(string []args)
    {
        int n = int.Parse(Console.ReadLine());

        Student[] lista = new Student[n];
        for(int i = 0; i < n; i++)
        {
            Console.WriteLine("Introdu detalii student(nume, an, nota1, nota2, nota3):");
            string nume = Console.ReadLine();
            int an = int.Parse(Console.ReadLine());
            double n1 = double.Parse(Console.ReadLine());
            double n2 = double.Parse(Console.ReadLine());
            double n3 = double.Parse(Console.ReadLine());
            Student s = new Student(nume, an, n1, n2, n3);
            lista[i] = s;
        }

        Student best = lista[0];
        for(int i = 1; i < n; i++)
        {
            if(lista[i].Medie > best.Medie)
                best = lista[i];
        }

        Console.WriteLine($"Cel mai bun student: {best}");
    }
}