class Fisier
{
    private String nume;
    private String continut;
    private int id;
    private static int cnt = 0;
    public Fisier fAnterior;
    private int numarConcatenari = 0;

    public Fisier(String nume, String continut)
    {
	this.nume = nume;
	this.continut = continut;
	cnt++;
	this.id = cnt;
    }

    public void salveazaVersiune()
    {
	Fisier fnou = new Fisier(nume + "bak", continut);
	fnou.fAnterior = fAnterior;
	fAnterior = fnou;
    }

    public void concateneaza(Fisier f)
    {
	salveazaVersiune();
	this.continut = this.continut + f.continut;
	this.numarConcatenari++;
    }

    public String toString()
    {
	if(fAnterior != null)
	    return id + " " + nume + " [" + continut + "] " + " <" +fAnterior.continut + "> ";
	else
	    return id + " " + nume + " [" + continut + "] ";
    }

    public int numarConcatenari()
    {
	return numarConcatenari;
    }
}

class main
{
    public static void main(String argv[])
    {
	Fisier f1 = new Fisier("test1.c", "printf(");
	Fisier f2 = new Fisier("test2.c", "Hello World!)");
	System.out.println(f1);
	System.out.println(f2);
	f1.salveazaVersiune();
	f1.concateneaza(f2);
	System.out.println(f1);
	System.out.println(f1.fAnterior);
	f1.salveazaVersiune();
	System.out.println(f1.fAnterior);
	System.out.println("Nr concatenari: " + f1.numarConcatenari());
    }
}
