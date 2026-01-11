import java.io.*;
import java.util.*;

interface Statistica
{
	public void calculeaza(List<String> l);
}

class StatisticaNumarAparitii implements Statistica
{
	private List<String> cautate = new ArrayList<String>();
	private String[] jurnal = new String[10];
	private int i = 0;

	public StatisticaNumarAparitii(List<String> cautate)
	{
		this.cautate = cautate;
	}

	public void calculeaza(List<String> l)
	{
		int k = 0;
		for(int y = 0; y < l.size(); y++)
		{
			for(int j = 0; j < cautate.size(); j++)
				if(l.get(y).equals(cautate.get(j)))
					k++;
		}

		String s = "In secventa {";
		for(int j = 0; j < cautate.size(); j++)
			s = s + cautate.get(j) + ",";
		s = s + "} apar " + k +" siruri din secventa {";
		for(int j = 0; j < l.size(); j++)
			s = s + l.get(j) + ",";
		s = s + "}";

		jurnal[i] = s;
		i++;
	}

	public String toString()
	{
		String s = "";
		for(int j = 0; j < i; j++)
			s = s + jurnal[j] + "\n";
		return s;
	}
}

class StatisticaNumeraleNonReale implements Statistica
{
	private String jurnal = "";
	
	public void calculeaza(List<String> l)
	{
		int k = 0;
		for(int i = 0; i < l.size(); i++)
		{
			try
			{
				Double.parseDouble(l.get(i));
			}
			catch(NumberFormatException e)
			{
				k++;
			}
		}

		String s = "In secventa {";
		for(int i = 0; i < l.size(); i++)
			s = s + l.get(i) + ",";
		s = s + "} avem " + k + " siruri ce nu sunt numerale reale";
		jurnal = jurnal + s + "\n";
	}

	public String toString()
	{
		return jurnal;
	}
}

class Executor
{
	private Statistica[] s;

	public Executor(Statistica[] s)
	{
		this.s = s;
	}

	public void executa(List<String> l)
	{
		for(int i = 0; i < s.length; i++)
			s[i].calculeaza(l);

		for(int i = 0; i < s.length; i++)
			System.out.println(s[i]);
	}
}

class Main
{
	public static void main(String[] args)
	{
		List<String> l = new ArrayList<String>();
		l.add("mere");
		l.add("pere");
		l.add("banane");
		StatisticaNumarAparitii s1 = new StatisticaNumarAparitii(l);
		StatisticaNumeraleNonReale s2 = new StatisticaNumeraleNonReale();

		Statistica[] s = new Statistica[2];
		s[0] = s1;
		s[1] = s2;
		Executor e = new Executor(s);

		List<String> l2 = new ArrayList<String>();
		l2.add("Ana");
		l2.add("are");
		l2.add("mere");

		List<String> l3 = new ArrayList<String>();
		l3.add("Maria");
		l3.add("are");
		l3.add("pere");

		e.executa(l2);
		e.executa(l3);
	}
}