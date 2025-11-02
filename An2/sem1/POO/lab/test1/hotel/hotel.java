class Camera
{
	private int nr;
	private String tip;
	private double pret;

	public int getNr()
	{
		return nr;
	}

	public String getTip()
	{
		return tip;
	}

	public double getPret()
	{
		return pret;
	}
}


class Rezervare
{
	private String nume;
	private int nr;
	private String check_in;
	private String check_out;

	public String getNume()
	{
		return nume;
	}

	public int getNr()
	{
		return nr;
	}

	public String getCheckIn()
	{
		return check_in;
	}

	public String getCheckOut()
	{
		return check_out;
	}
}

class Hotel
{
	private Camera[] c = new Camera[100];
	private int nc;
	private Rezervare[] r = new Rezervare[100];
	private int nr;

	public boolean adaugaCamera(Camera cam)
	{
		if(nc == 100)
			return false;
		else
		{
			int ok = 1;
			for(int i = 0; i < nc; i++)
				if(cam.getNr() == c[i].getNr())
					ok = 0;
			if(ok == 1)
			{
				nc++;
				c[nc-1] = cam;
				return true;
			}
			return false;
		}
	}

	public boolean adaugaRezervare(Rezervare rez)
	{
		if(nr == 100)
			return false;
		else
		{
			int ok = 1;
			for(int i = 0; i < nr; i++)
				if(rez.getNr() == r[i].getNr())
					ok = 0;
			if(ok == 1)
			{
				nr++;
				r[nr-1] = rez;
				return true;
			}
			return false;
		}
	}

	public void afiseazaRez(String nume)
	{
		for(int i = 0; i < nr; i++)
			if(nume.equals(r[i].getNume()))
				System.out.println("Nume: " + r[i].getNume() + ", Nr: " + r[i].getNr() + ", Check-in: " + r[i].getCheckIn() + ", Check-out: " + r[i].getCheckOut());

	}
}

class Main
{
	public static void main(String[] argv)
	{
		
	}
}