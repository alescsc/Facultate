// lab 8 poo

/*
POLIMORFISM & CLASE ABSTRACTE


Vehicul m = new Masina();
- daca apelam functii din masina apelam cu typecast

Masina m = new Masina();
- asa nu e nevoie de typecast

Vehicul[] v = new Vehicul[3];
v.add(new Masina()); - adaug element in vector

abstract class Vehicul
- nu mai putem sa folosim new Vehicul();
- pot sa creez un tablou;

abstract public void claxoneaza(); - metoda nu e folosita niciodata, doar suprascrisa

*/

abstract class Greutati
{
    abstract public int capacitate();
}

class Simpla extends Greutati
{
    private int cap;
    public Simpla(int cap)
    {
        this.cap = cap;
    }
    public int capacitate()
    {
        return cap;
    }

    
}

class Dubla extends Greutati
{
    private Greutati g1, g2;

    public Dubla(Greutati g1, Greutati g2)
    {
        this.g1 = g1;
        this.g2 = g2;
    }

    public void setGreutate1(Greutati g)
    {
        g1 = g;
    }

    public void setGreutate2(Greutati g)
    {
        g2 = g;
    }

    public int capacitate()
    {
        return g1.capacitate() + g2.capacitate();
    }
}

class Multipla extends Greutati
{
    private Greutati[] g = new Greutati[5];

    public Multipla(Greutati[] g)
    {
        this.g = g;
    }

    public int capacitate()
    {
        int s = 0;
        for(int i = 0; i < g.length; i++)
            {
                s = s + g[i].capacitate();
            }
        return s;
    }
}

class ColectieGreutati
{
    private Greutati[] g = new Greutati[3];
    private int contor = 0;
    public void adauga(Greutati g)
    {
        this.g[contor] = g;
        contor++;
    }

    public double medie()
    {
        int s = 0;
        for(int i = 0; i < g.length; i++)
            s = s + g[i].capacitate();
        return s/g.length;
    }
}

class Main
{
    public static void main(String[] args)
    {
        Simpla s = new Simpla(10);
        System.out.println(s.capacitate());

        Simpla s2 = new Simpla(115);

        Dubla d = new Dubla(s,s);
        System.out.println(d.capacitate());

        Multipla m = new Multipla(new Greutati[]{s,s,d,s2});
        System.out.println(m.capacitate());
    }
}
