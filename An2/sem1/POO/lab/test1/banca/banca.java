import java.io.*;

class Banca
{	
	private ContBancar cb[] = new ContBancar[100];
	private int nrcb;

	public void adaugaCont(ContBancar cont)
	{
		int ok = 1;
		for(int i = 0; i < nrcb; i++)
			if(cont.getNr() == cb[i].getNr())
				ok = 0;
		if(ok == 1)
		{
			nrcb++;
			cb[nrcb-1] = cont;
		}
	}

	public void afiseazaConturi()
	{
		for(int i = 0; i < nrcb; i++)
			System.out.println("Numar cont: " + cb[i].getNr() + ", Titular: " + cb[i].getNume() + ", Sold: " + cb[i].getSold());
	}

	public double soldTotal()
	{
		double s = 0; 
		for(int i = 0; i < nrcb; i++)
			s = s + cb[i].getSold();
		return s;
	}

	public String conturiSubSoldMinim(double soldMinim)
	{
		String sir = "";
		for(int i = 0; i < nrcb; i++)
			if(cb[i].getSold() < soldMinim)
				sir = sir + cb[i].getNume() + " ";
		return sir;
	}
}

class ContBancar
{
	private int nr;
	private String nume;
	private double sold;

	public ContBancar(int nr, String nume, double sold)
	{
		this.nr = nr;
		this.nume = nume;
		this.sold = sold;
	}

	public int getNr()
	{
		return nr;
	}

	public String getNume()
	{
		return nume;
	}

	public double getSold()
	{
		return sold;
	}
}

class Main
{
	public static void main(String []argv)
	{
		try
		{
			FileInputStream fsr = new FileInputStream(argv[0]);
			BufferedReader br = new BufferedReader(new InputStreamReader(fsr));
			//int n = Integer.parseInt(br.readLine());

			int n = Integer.parseInt(argv[1]);
			System.out.println(n);

			Banca b = new Banca();

			for(int i = 0; i < n; i++)
			{
				int nr = Integer.parseInt(br.readLine());
				String nume = br.readLine();
				double sold = Double.parseDouble(br.readLine());

				ContBancar cb = new ContBancar(nr, nume, sold);
				b.adaugaCont(cb);

			}
			b.afiseazaConturi();
			System.out.println("Soldul total este: " + b.soldTotal());
			System.out.println("Sold sub 200: " + b.conturiSubSoldMinim(200));
			fsr.close();
			br.close();

		} 
		catch(IOException e)
		{
			System.out.println("Eroare la citire!");
		}
	}
}