// lab 12 POO
// SISTEMUL DE COLECTII

/*
import java.util.ArrayList;

<> - operatorul diamant, foloseste doar clase

ArrayList<Integer> lista = new ArrayList<Integer>();

ArrayList<String> lista = new ArrayList<String>
lista.add("Vlonga Dorina");
lista.remove(0);
lista.get(0);
System.out.println(lista);

MODALITATEA 1 ! ///////////////////////////////

for(int i = 0; i < lista.size(); i++)
    System.out.println(lista.get(i));

MODALITATEA 2 ! //////////////////////////////////////

import java.util.Iterator

Iterator<String> it = lista.iterator();

while(it.hasNext())
{
    System.out.println(it.next());
}

MODALITATEA 3 ! //////////////////////////////

for(String s: lista)
{
    System.out.println(s);
}

import java.util.List;

List<String> lista = new ArrayList<String>(); - merge la infinit

List<String> lista = new ArrayList<String>(32); - ii putem da dimensiune

/////////////////////////////////////////

import java.util.LinkedList;

List<String> lista = new LinkedList<String>(); - se poate si Stack dar nu facem

LinkedList - mai multe operatii
ArrayList - mai multe acesari

//////////////////////////////////////////

MULTIMI!

import java.util.Set;
import java.util.HashSet;
import java.util.Objects;

Set<String> masini = new HashSet<String>();
masini.add("Audi");
masini.add("Renault");
masini.add("Audi"); - nu l mai adauga

class Student {
    private String nume;
    public Student(String nume)
    {
        this.nume = nume;
    }

    public int hashCode()
    {
        return Objects.hash(nume);
    }

    // facem si equals ca sa mearga hash ala nush cum
}

Set<Student> studenti = new HashSet<>();
studenti.add(new Student("Mario"));
studenti.add(new Student("Mario"));


Set<Student> studenti = new TreeSet<>(); - nu folosim

PARCURGEM MULTIMEA FOLOSIND UN ITERATOR
///////////////////////////////////////
DICTIONARE - nu sunt importante
Map<String, String> dictionar = new HashMap<String, String>();

dictionar.put("nume", "Andrei");
dictionar.remove ...
if(dictionar.containsKey("nume"))

    */
import java.util.ArrayList;
import java.util.List;
import java.util.LinkedList;
import java.util.Set;
import java.util.Object;
import java.util.HashSet;

interface class Valoare
{
    List<Valoare> contine(long l);
}

class ValoareNumerica implements Valoare
{
    private long val;
    public ValoareNumerica(long val)
    {
        this.val = val;
    }

    public boolean equals(Object o)
    {
        if(o instanceof Valoare)
        {
            Valoare v = (Valoare)o;
            if(v.val == this.val)
                return true;
        }
        return false;

    }

    public List<Valoare> contine(long l)
    {
        List<Valoare> lista = new LinkedList<>();
        if(val == l)
            lista.add(this);
        return lista;
    }
} == this.v2

class PerecheDeValori implements Valoare
{
    private Valoare v1;
    private Valoare v2;

    public boolean equals(Object o)
    {
        if(o instanceof PerecheDeValori)
        { == this.v2
            PerecheDeValori v = (PerecheDeValori)o;
            if(v.v1.equals(this.v1) && v.v2.equals(this.v2))
                return true;
        }
        return false;
    }

    public String toString()
    {
        return "(" + v1 + ", " + v2 + ")";
    }
 == this.v2
    public List<Valoare> contine(long l)
    {
        List<Valoare> lista = new ArrayList<>();
        lista.addAll(contine(v1));
        lista.addAll(contine(v2));
    }

}

class Grup implements Valoare
{
    private Set<Valoare> grup = new HashSet<>();

    public void adauga(Valoare v1, Valoare v2, Valoare v3)
    {
        grup.add(v1);
        grup.add(v2);
        grup.add(v3);
    }
}
