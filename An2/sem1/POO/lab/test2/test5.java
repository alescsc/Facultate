import java.util.*;
import java.io.*;

abstract class Utilizator
{
	protected String nume;

	public Utilizator(String nume)
	{
		this.nume = nume;
	}

	abstract public double calculeazaVenit(int min);
}

class Subscriber extends Utilizator
{
	private int nivel_sub;

	public Subscriber(String nume, int nivel_sub)
	{
		super(nume);
		this.nivel_sub = nivel_sub;
	}

	public double calculeazaVenit(int min)
	{
		return 1.5*min*nivel_sub;
	}

	public String toString()
	{
		return nume + " - subscriber - " + nivel_sub;
	}
}

class Creator extends Utilizator
{
	private List<Subscriber> l = new ArrayList<Subscriber>();

	public Creator(String nume)
	{
		super(nume);
	}

	public void adaugaSubscriber(Subscriber s)
	{
		l.add(s);
	}

	public double calculeazaVenit(int min)
	{
		double s = 0;
		for(int i = 0; i < l.size(); i++)
			s = s + l.get(i).calculeazaVenit(min);
		return s;
	}

	public String toString()
	{
		String s = nume + " - creator -";
		for(int i = 0; i < l.size(); i++)
			s = s + l.get(i).toString() + "|";
		return s;
	}
}

class Platforma
{
	private List<Utilizator> l = new ArrayList<Utilizator>(1000);
	private int size = 0;

	public boolean adaugaUtilizator(Utilizator u)
	{
		if(size != 1000)
		{
			l.add(u);
			size++;
			return true;
		}
		else return false;
	}

	public Utilizator determinaVIP(int min)
	{
		Utilizator max = null; // max = l.get(0);
		for(int i = 0; i < l.size(); i++)
			if(max == null || l.get(i).calculeazaVenit(min) > max.calculeazaVenit(min))
				max = l.get(i);
		return max;
	}
}

class Main
{
	public static void main(String[] args)
	{
		Subscriber s1 = new Subscriber("Andrei", 1);
		Subscriber s2 = new Subscriber("Ioana", 1);
		Subscriber s3 = new Subscriber("Eusebiu", 2);
		Subscriber s4 = new Subscriber("Dori", 3);
		Subscriber s5 = new Subscriber("Alex", 3);
		Subscriber s6 = new Subscriber("Marian", 1);

		Creator c1 = new Creator("Imi place sa mananc");
		c1.adaugaSubscriber(s1);
		c1.adaugaSubscriber(s2);

		Creator c2 = new Creator("Lenghel");
		c2.adaugaSubscriber(s3);
		c2.adaugaSubscriber(s4);
		c2.adaugaSubscriber(s5);

		Platforma yt = new Platforma();
		yt.adaugaUtilizator(c1);
		yt.adaugaUtilizator(c2);
		yt.adaugaUtilizator(s6);

		System.out.println(c1);
		System.out.println(c2);
		System.out.println(yt.determinaVIP(30));	
	}
}