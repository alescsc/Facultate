abstract class Destinatar 
{
	protected String nume;

	public Destinatar(String nume)
	{
		this.nume = nume;
	}
	abstract public void receptioneaza(Utilizator u, String mesaj);
}

class Utilizator extends Destinatar
{
	private String[] jurnal = new String[10];
	private int i = 0;

	public Utilizator(String nume)
	{
		super(nume);
	}

	public boolean equals(Object o)
	{
		Utilizator u = (Utilizator)o;
		if(o instanceof Utilizator)
			if(u.nume.equals(this.nume)) 
				return true;
			else return false;
		return false;
	}

	public void trimite(Destinatar d, String mesaj)
	{
		this.jurnal[i] = "Trimis catre " + d.nume + " mesajul:" + mesaj; 
		d.receptioneaza(this, mesaj);
		i++;
	}

	public void receptioneaza(Utilizator u, String mesaj)
	{
		this.jurnal[i] = "Primit de la " + u.nume + " mesajul:" + mesaj;
		i++;
	}

	public void afiseaza()
	{
		System.out.println(this.nume + ":");
		for(int j = 0; j < i; j++)
			System.out.println(jurnal[j]);
	}
}

class DestinatarDuplicat extends Exception
{}

class Grup extends Destinatar
{
	private Utilizator[] u = new Utilizator[10];
	private int i = 0;

	public Grup(String nume)
	{
		super(nume);
	}

	public void inscrie(Utilizator u1) throws DestinatarDuplicat
	{
		int ok = 1;
		for(int j = 0; j < i; j++)
			if(u[j].equals(u1))
				ok = 0;
		if(ok == 1)
		{
			u[i] = u1;
			i++;
		}
		else throw new DestinatarDuplicat();
	}

	public void receptioneaza(Utilizator u1, String mesaj)
	{
		for(int j = 0; j < i; j++)
			if(u1.equals(u[j]) == false)
				u[j].receptioneaza(u1, mesaj);	
	}
}

class Main
{
	public static void main(String[] args)
	{
		
			Utilizator u1 = new Utilizator("Dan");
			Utilizator u2 = new Utilizator("Marius");
			Utilizator u3 = new Utilizator("Alex");
			Grup g = new Grup("Carnivorii");
			g.inscrie(u1);
			g.inscrie(u2);
			g.inscrie(u3);
			try 
		{
			g.inscrie(u3);
		}catch(DestinatarDuplicat d)
		{
			System.out.println("Utilizatorul exista deja in grup!");
		}
			u3.trimite(g, "Am deschis magazinul");
			u2.trimite(g, "Vin acuma");
			u1.afiseaza();
			u2.afiseaza();
			u3.afiseaza();
	}
}