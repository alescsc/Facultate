// Laborator 1

using System;// ca si import din Java 

namespace lab1 // la fel ca si package in Java
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Salut!"); // afisare
            Console.ReadLine(); // citire

// namespace poate sa fie scris si pe un singur rand fara acolade:
// namespace lab1;

// Top-level statements
// > poti scrie programul fara clasa si fara Main!
Console.WriteLine("Salut!");

// Citirea numerelor
int n = int.Parse(Console.ReadLine()); // returneaza un 'string?', poate primi null
int m = int.Parse(Console.ReadLine()!); // nu mai primesti warning

// Citiri in C#
string nume = Console.ReadLine(); // direct, nu necesita conversie
int varsta = int.Parse(Console.ReadLine());
float viteza = float.Parse(Console.ReadLine());
// etc pt orice alt tip


Console.WriteLine($"Viteza = {viteza}"); // $ pentru a introduce valorile variabilelor in mesaj!

// Math e introdus automat! => folosesti Math.Sqrt(x) oricand

// Particularitati clase
// public string Nume {get; private set;} // get; - getter, private set; - setter privat!    
// public override string ToString(); override este obligatoriu

// proprietatea poate sa fie facuta si asa: 
/*
    public double Medie
    {
        get { return (n1 + n2 + n3)/3.0; } 
    } 
*/

// proprietatea privata: public string nume {get;}

// FLOAT!
// daca imparti si vrei rezultat cu virgula, trebuie sa faci nr/3.0 in loc de nr/3
double Media;
Console.WriteLine($"Media = {Media:F2}"); // pt a afisa media doar cu 2 zecimale dupa virgula

// functii fara a crea obiect => static

// LABORATOR 2
// Proprietati 
    class Persoana
{
    public string Nume { get; set; }              // citire si scriere
    public int Varsta { get; private set; }       // scriere doar in clasa
    public string Cnp { get; }                    // doar in constructor
    public string Oras { get; init; } = "Timisoara"; // doar la initializare
    public bool EMajor => Varsta >= 18;           // calculata
}
public double Suma { get; private set; } // folosim private set atunci cand stim ca o sa se modifice valoarea


const double pi = 3.14; // constanta

// Interface:
interface Interfata {}
class Clasa : Interfata {} // asa o mosteneste

// Liste!
using System.Collections.Generic;  // pt a folosi liste

List<int> lista = new List<int>; // creare lista, o initializam mereu chiar daca la inceput e goala

Lista.Add(int); // new Cont() - daca folosim clase, daca folosim variabile simple doar: int, string, etc
Lista.Count(); // ne da cate elemente sunt in lista

private Cont? GetAccount(...) // folosim Cont? cand fie primim drept rezultat un Cont sau null

public enum TipCont // asa se face un enum
    {
        Personal,
        Companie
    }


    
        }
    }
}