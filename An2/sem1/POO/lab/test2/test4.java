import java.util.*;
import java.io.*;

abstract class Autovehicule
{
	protected String nr;
	protected double greutate;

	public Autovehicule(String nr, double greutate)
	{
		this.nr = nr;
		this.greutate = greutate;
	}

	abstract public double calculeazaGreutateTotala();
}

class Autoturism extends Autovehicule
{
	private double greutate_pas;

	public Autoturism(String nr, double greutate, double greutate_pas)
	{
		super(nr, greutate);
		this.greutate_pas = greutate_pas;
	}

	public double calculeazaGreutateTotala()
	{
		return greutate + greutate_pas;
	}

	public String toString()
	{
		return "Numar inmatriculare: " + nr + ", Greutate autovehicul: " + greutate + ", Greutate pasageri: " + greutate_pas;
	}
}

class Camion extends Autovehicule
{
	private List<Autoturism> l = new ArrayList<Autoturism>();

	public Camion(String nr, double greutate)
	{
		super(nr, greutate);
	}

	public void adaugaAutoturism(Autoturism a)
	{
		l.add(a);
	}

	public double calculeazaGreutateTotala()
	{
		double s = greutate;
		for(int i = 0; i < l.size(); i++)
			s = s + l.get(i).calculeazaGreutateTotala();
		return s;
	}

	public String toString()
	{
		String s = "Numar inmatriculare: " + nr + ", Greutate autovehicul: " + greutate + " (";
		for(int i = 0; i < l.size(); i++)
			s = s + l.get(i).toString() + ",";
		s = s + ")";
		return s;
	}
}

class Bac
{
	private double greutate_max;
	private double greutate_curenta = 0;

	private List<Autovehicule> l = new ArrayList<Autovehicule>();

	public boolean adaugaAutovehicul(Autovehicule a)
	{
		greutate_curenta = greutate_curenta + a.calculeazaGreutateTotala();
		if(greutate_curenta > greutate_max)
		{
			greutate_curenta = greutate_curenta - a.calculeazaGreutateTotala();
			return false;
		}
		else
		{
			l.add(a);
			return true;
		}
	}

	public Bac(double greutate_max)
	{
		this.greutate_max = greutate_max;
	}

	public String toString()
	{
		String s = "Greutate maxima: " + greutate_max + " (";
		for(int i = 0; i < l.size(); i++)
			s = s + l.get(i).toString();
		s = s + ")";
		return s;
	}
}

class Main
{
	public static void main(String[] args)
	{
		Autoturism a1 = new Autoturism("AR03FIZ", 4, 0.3);
		Autoturism a2 = new Autoturism("AR65LCH", 5, 0.25);
		Autoturism a3 = new Autoturism("BH69LEN", 4.5, 0.15);
		Camion c = new Camion("TM13DOR", 10);
		c.adaugaAutoturism(a1);
		c.adaugaAutoturism(a2);
		Bac b = new Bac(20);
		b.adaugaAutovehicul(c);
		b.adaugaAutovehicul(a3);
		System.out.println(b);
	}
}