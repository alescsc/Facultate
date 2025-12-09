abstract class Angajat
{
    protected String nume;

    public Angajat(String nume)
    {
        this.nume=nume;
    }

    public abstract double calculSalar();
}

class AngajatCuSalarFix extends Angajat
{
    private double salarFix;

    public AngajatCuSalarFix(String nume, double salarFix)
    {
        super(nume);
        this.salarFix = salarFix;
    }

    public double calculSalar()
    {
        return salarFix;
    }

    public void schimbaSalarFix(double nouSalar)
    {
        this.salarFix = nouSalar;
    }
}

class AngajatCuOra extends Angajat
{
    private double salarPeOra;
    private double[] oreLucrate = new double[31];
    private int nrZile = 0;

    public AngajatCuOra(String nume, double salarPeOra)
    {
        super(nume);
        this.salarPeOra = salarPeOra;
    }

    public void adaugaOre(double ore)
    {
        if(nrZile < 31)
       {
            oreLucrate[nrZile] = ore;
            nrZile++;
       }
    }

    public void schimbaSalarPeOra(double nouSalar)
    {
        salarPeOra = nouSalar;
    }

    public double calculSalar()
    {
        double total = 0;
        for(int i = 0; i < nrZile; i++)
            total = total + oreLucrate[i];
        return total*salarPeOra;
    }
}

class Firma
{
    private Angajat[] an = new Angajat[1024];
    private int nrAngajati = 0;

    public int angajeaza(Angajat a)
    {
        if(nrAngajati >= 1024)
            return -1;
        for(int i = 0; i < nrAngajati; i++)
            {
                if(an[i].nume.equals(a.nume))
                    return -2;
            }
        an[nrAngajati] = a;
        nrAngajati++;
        return 0;
    }

    public double salariuMediu()
    {
        if(nrAngajati ==0 )
            return 0;
        double suma = 0;
        for(int i = 0; i < nrAngajati; i++)
            suma = suma + an[i].calculSalar();
        return suma/nrAngajati;
    }
}

class Main
{
    public static void main(String[] args)
    {
        Firma f = new Firma();

        AngajatCuSalarFix fix1 = new AngajatCuSalarFix("Alex", 4000);
        AngajatCuSalarFix fix2 = new AngajatCuSalarFix("Maria", 5000);
        
        AngajatCuOra ora1 = new AngajatCuOra("Irinel", 50);
        AngajatCuOra ora2 = new AngajatCuOra("George", 60);

        ora1.adaugaOre(8); 
        ora1.adaugaOre(8);
        ora2.adaugaOre(4);

        System.out.println("Adaugare Alex: " + f.angajeaza(fix1));
        System.out.println("Adaugare Maria: " + f.angajeaza(fix2));
        System.out.println("Adaugare Irinel: " + f.angajeaza(ora1));
        System.out.println("Adaugare George: " + f.angajeaza(ora2));
        System.out.println("Adaugare Alex iar: " + f.angajeaza(fix1));

        System.out.println("Salariu mediu initial: " + f.salariuMediu());

        System.out.println("Marim salariul lui Alex la 4800");
        fix1.schimbaSalarFix(4800); 
        
        System.out.println("Noul salariu mediu: " + f.salariuMediu());
    }
}