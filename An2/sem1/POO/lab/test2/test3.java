abstract class Teste
{
	protected String nume;
	protected int cantitate;

	public Teste(String nume, int cantitate) throws WrongQualityIndicatorException
	{
		this.nume = nume;
		if(cantitate >= 1 && cantitate <= 10)
			this.cantitate = cantitate;
		else throw new WrongQualityIndicatorException();
	}

	public int getNumarTeste() 
	{
		return 1;
	}
}

class WrongQualityIndicatorException extends Exception
{}

class WrongComponentComplexityIndicatorException extends Exception
{}

class IntegrationTest extends Teste
{
	public IntegrationTest(String nume, int cantitate) throws WrongQualityIndicatorException
	{
		super(nume, cantitate);
	}

	public String toString()
	{
		String s = "";
		s = "IntegrationTest(name=[" + nume + "],quality indicator=[" + cantitate + "])";
		return s;
	}
}

class ComponentTest extends Teste 
{
	private int complexitate;
	public ComponentTest(String nume, int cantitate, int complexitate) throws WrongComponentComplexityIndicatorException, WrongQualityIndicatorException
	{
		super(nume, cantitate);
		if(complexitate < 0)
			throw new WrongComponentComplexityIndicatorException();
		else this.complexitate = complexitate;
	}

	public String toString()
	{
		return "ComponentTest(name=[" + nume + "], quality indicator=[" + cantitate + "], component complexity indicator=[" + complexitate + "])"; 
	}
}

class TestSuite
{
	Teste[] t = new Teste[10];
	private int i = 0;

	public boolean addNewIntegrationTest(String nume, int indicator)
	{
		try 
		{
			IntegrationTest it = new IntegrationTest(nume, indicator);
			t[i] = it;
			i++;
			return true;
		}
		catch(WrongQualityIndicatorException w)
		{
			return false;
		}
	}

	public boolean addNewComponentTest(String nume, int indicator, int complexity) throws WrongQualityIndicatorException
	{
		try 
		{
			ComponentTest ct = new ComponentTest(nume, indicator, complexity);
			t[i] = ct;
			i++;
			return true;
		}
		catch(WrongQualityIndicatorException w)
		{
			return false;
		}
	}

	public String toString()
	{
		String s = "(";
		for(int j = 0; j < i; j++)
			s = s + t[j].toString() + " ";
		s = s + ")";
		return s;
	}
}

class Main
{
	public static void main(String[] args)
	{
		TestSuite ts = new TestSuite();

		ts.addNewIntegrationTest("Dorina", 10);
		ts.addNewIntegrationTest("Pepi", 8);
		try 
		{
			ts.addNewComponentTest("Axa", 4, 2);
			ts.addNewComponentTest("Vlonghi", 10, 10);
		}
		catch(WrongComponentComplexityIndicatorException w)
		{
			System.out.println("a aparut o exceptie");
		}
	}
}