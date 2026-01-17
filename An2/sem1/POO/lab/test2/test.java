import java.util.*;

abstract class Operatie
{
	protected String identificator;

	public Operatie(String identificator)
	{
		this.identificator = identificator;
	}
	
	public boolean equals(Object o)
	{
		Operatie s = (Operatie)o;
		if(o instanceof Operatie)
		{
			if(this.identificator.equals(s.identificator))
				return true;
			else
				return false;
		}
		else
			return false;
	}

	abstract public int calculeazaComplexitate();
}

class OperatieElementara extends Operatie
{
	private int cost; 
	
	public OperatieElementara(String identificator, int cost)
	{
		super(identificator);
		this.cost = cost;
	}
	
	public int calculeazaComplexitate()
	{
		return cost;
	}
}

class BlocOperatii extends Operatie
{ 
	private List<Operatie> l = new ArrayList<Operatie>();
	
	public BlocOperatii(String identificator, List<Operatie> l)
	{
		super(identificator);
		this.l = l;
	} 
	
	public int calculeazaComplexitate()
	{
		int comp = 0;
		for(int i = 0; i < l.size(); i++)
			comp = comp + l.get(i).calculeazaComplexitate();
		return comp;
	}
}

class ComplexitateExcesiva extends Exception
{}

class OperatieDuplicata extends Exception
{}

class Algoritm
{
	private int buget;
	private List<Operatie> l = new ArrayList<Operatie>();
	
	public Algoritm(int buget)
	{
		this.buget = buget;
	}
	
	public void insereaza(Operatie o) throws ComplexitateExcesiva, OperatieDuplicata
	{
		int bugetcur = 0;
		for(int i = 0; i < l.size(); i++)
			bugetcur = bugetcur + l.get(i).calculeazaComplexitate();
		if(bugetcur + o.calculeazaComplexitate() > buget)
			throw new ComplexitateExcesiva();
		else
		{
			for(int i = 0; i < l.size(); i++)
				if(((o instanceof OperatieElementara && l.get(i) instanceof OperatieElementara) || (o instanceof BlocOperatii && l.get(i) instanceof BlocOperatii)) && (o.equals(l.get(i))))
				throw new OperatieDuplicata(); 
			l.add(o);
		} 
	}
	
	public Operatie operatieCeaMaiCostisitoare()
	{
		if(l.get(0) == null)
			return null;
		Operatie max = l.get(0);
		for(int i = 1; i < l.size(); i++)
			if(l.get(i).calculeazaComplexitate() > max.calculeazaComplexitate())
				max = l.get(i);
		return max;
	}
}

class Main 
{
	public static void main(String[] args)
	{
		OperatieElementara oe1 = new OperatieElementara("oe1", 1);
		OperatieElementara oe2 = new OperatieElementara("oe2", 2);
		OperatieElementara oe3 = new OperatieElementara("oe3", 5);
		OperatieElementara oe4 = new OperatieElementara("oe4", 5);
		
		List<Operatie> l = new ArrayList<Operatie>();
		l.add(oe3);
		l.add(oe4);
		BlocOperatii b = new BlocOperatii("b", l);
		
		Algoritm a = new Algoritm(6);
		try
		{
			a.insereaza(oe1);
			a.insereaza(b);
		}
		catch(ComplexitateExcesiva c)
		{
			System.out.println("Complexitate excesiva!");
		}
		catch(OperatieDuplicata c)
		{
			System.out.println("Operatie duplicata!");
		}
		
		try
		{
			a.insereaza(oe1);
			a.insereaza(oe1);
		}
		catch(ComplexitateExcesiva c)
		{
			System.out.println("Complexitate excesiva!");
		}
		catch(OperatieDuplicata c)
		{
			System.out.println("Operatie duplicata!");
		}
		
		Algoritm a2 = new Algoritm(50);
		
		try 
		{
			a2.insereaza(oe1);
			a2.insereaza(b);
		}
		catch(ComplexitateExcesiva c)
		{
			System.out.println("Complexitate excesiva!");
		}
		catch(OperatieDuplicata c)
		{
			System.out.println("Operatie duplicata!");
		}
		System.out.println("Complexitatea operatiei cea mai costisitoare: " + a2.operatieCeaMaiCostisitoare().calculeazaComplexitate());
	}
}

