import java.io.*;
import java.util.*;

class nume
{
	// EQUALS
	public boolean equals(Object o)
	{
		nume n = (nume)o;
		if(o instanceof nume)
		{
			// verificare n.variabila si cu variabila
				return true;
			return false;
		}
		return false;
		// in main se apeleaza variabila.equals(variabila2);
	} 

	// TO STRING
	public String toString()
	{
		String s = " ... ";
		// ...
		return s;
		// in main se apeleaza System.out.println(variabila);
	}
}

// CITIRE SI AFISARE

class Main
{
	public static void main(String []argv)
	{
		try 
		{
			// citire tastatura
			InputStreamReader isr = new InputStreamReader(System.in);
			BufferedReader br = new BufferedReader(isr);

			// citire fisier
			/*
			FileInputStream fis = new FileInputStream("fisier.txt");
			BufferedReader br2 = new BufferedReader(new InputStreamReader(fis));*/

			// daca citim int
			int n = Integer.parseInt(br.readLine());

			// daca citim string
			String s = br.readLine();
			// ...
		}
		catch(IOException e)
		{
			System.out.println("Nu s-a putut citi!");
		}	
	}
}

// --------------------------------------------------------------------------------- //

// extends

class Animal
{
	protected int nr_picioare;
	public Animal(int nr_picioare)
	{
		this.nr_picioare = nr_picioare;
	}
}

class Caine extends Animal
{
	private int varsta;
	public Caine(int nr_picioare, int varsta)
	{
		super(nr_picioare);
		this.varsta = varsta;
	}
	public void latra()
	{
		System.out.println("Hamham");
	}
}

// in main

Animal a = new Caine(4, 2);
((Caine)a).latra();
// SAU
Caine c = new Caine(4, 2);
c.latra();

Animal[] a = new Animal[3];
a.add(new Caine(...));

//

// abstract class - are metode abstracte + comune si poate avea variabile

abstract class Animal
{
	abstract public void vorbeste();

	public void merge()
	{
		System.out.println("animalu merge!");
	}
}

class Caine extends Animal
{
	public void vorbeste()
	{
		System.out.println("ham");
	}
}

class Pisica extends Animal
{
	public void vorbeste()
	{
		System.out.println("miau");
	}
}

// interfata - are doar metode abstracte

interface Animal
{
	public void latra();
}

class Caine implements Animal
{
	public void latra()
	{
		//...
	}
}

// EXCEPTIONS

class Gol extends Exception 
{}

class Minge
{
	// ...

	public void suteaza() throws Gol // se pot adauga mai multe
	{
		// ...
		// bla bla bla 
		if(conditie)
			throw new Gol();
	}
}

// apoi in main sau in metoda altei clase, cand apelam suteaza apelam asa:

try {
	variabila.suteaza();
	// ...
} catch(Gol e)
{
	System.out.println("Gol!");
	//...
} // se pot avea mai multe catchuri in functie de cate exceptii

// LISTE

List<String> lista = new ArrayList<String>();
List<String> lista = new LinkedList<String>();


lista.add("Vlonga Dorina"); // o baga pe dorina
lista.get(0); // o ia pe dorina
lista.remove(0); // o remove pe dorina
System.out.println(lista); // o printeaza pe dorina

// PARCURGERE

for(int i = 0; i < lista.size(); i++)
	System.out.println(lista.get(i));

// STERGERE de pe pozitie sau stergere valoare

for(int i = 0; i < lista.size(); i++)
	if(i == k) // k - pozitie
	{
		lista.remove(i);
		i--;	
	}
	else 
		if(lista.get(i) == k) // k - valoare
		{
			lista.remove(i);
			i--;
		}

// parcurgere cu iterator

Iterator<String> it = lista.iterator();
while(it.hasNext())
{
	System.out.println(it.next());
}

// stergere cu iterator

while(it.hasNext())
{
	String nume = it.next();
	if(nume.equals("Dori"))
		it.remove();
}

// parcurgere 3

for(String s: lista)
{
	System.out.println(s);
}

// MULTIMI

Set<String> masini = new HashSet<String>();
masini.add("Audi");
masini.add("Renault");
masini.add("Audi") - nu mai adauga

// daca avem multime pe o clasa facuta de noi, trebuie sa facem
// hashcode si equals

class Student
{
	private String nume;
	private int varsta;
	// ...

	public int hashCode()
	{
		return Objects.hash(nume);
	}

	public boolean equals(Object o)
	{
		Student s = (Student)o;
		if(o instanceof Student)
		{
			if(s.nume.equals(this.nume))
				return true;
			else 
				return false;
		}
		return false;
	}
}

Set<Student> studenti = new HashSet<>();
studenti.add(new Student("Mario"));
studenti.add(new Student("Mario")); //- nu adauga mario 2