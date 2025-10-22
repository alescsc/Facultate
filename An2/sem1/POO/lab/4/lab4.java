class Tir
{
    private Remorca r[] = new Remorca[5];
    private int size = 0;
    public boolean adaugaRemorca(int cantitate, String nrInmatriculare)
    {
	Remorca rem = new Remorca(cantitate, nrInmatriculare);
	if(size == 5)
	    return false;
	else
	    {
		r[size] = rem;
		size++;
		return true;
	    }
    }

    public boolean adaugaRemorca(Remorca rem)
    {
	if(size == 5)
	    return false;
	else
	    {
		r[size] = rem;
		size++;
		return true;
	    }
    }

    public Remorca stergeRemorca(String nr)
    {
	for(int i = 0; i < r.length; i++)
	    if(r[i].getnrInmatriculare().equals(nr))
		{
		    Remorca temp = r[i];
		    for(int j = i; j < r.length - 1; j++)
			r[j] = r[j+1];
		    size--;
		    return temp;
		}
	return null;
		
    }

    public boolean equals(Object o)
    {
	Tir t = (Tir)o;
	if(o instanceof Tir)
	    {
		for(int i = 0; i < r.length; i++)
		    if(r[i].getcantitate() != t.r[i].getcantitate())
			return false;
		return true;
	    }
	return false;
    }
    public String toString()
    {
        String s = "T->";
	for(int i = 0; i < size; i++)
	    s = s + "R(" + r[i].getnrInmatriculare() + "," + r[i].getcantitate() + ")";
	return s;
    }
}

class Remorca
{
    private int cantitate;
    private String nrInmatriculare;
    private static int cnt = 10;
    public Remorca(int cantitate, String nrInmatriculare)
    {
	this.cantitate = cantitate;
	this.nrInmatriculare = nrInmatriculare;
    }
    public Remorca(String nrInmatriculare)
    {
	cantitate = cnt;
	cnt++;
	this.nrInmatriculare = nrInmatriculare;
    }
    public String getnrInmatriculare()
    {
	return nrInmatriculare;
    }
    public int getcantitate()
    {
	return cantitate;
    }
}

class Main
{
    public static void main(String[] args)
    {
	Tir t1 = new Tir();
	t1.adaugaRemorca(5,"AR03FIZ");
	t1.adaugaRemorca(6,"AR67LCH");
	t1.adaugaRemorca(7,"TM69LOL");
	t1.adaugaRemorca(12,"AR23TMM");
	t1.adaugaRemorca(2,"BH67POO");
	System.out.println(t1);
	Tir t2 = new Tir();
	t2.adaugaRemorca(5,"AR03FIZ");
	t2.adaugaRemorca(6,"AR67LCH");
	t2.adaugaRemorca(7,"TM69LOL");
	t2.adaugaRemorca(12,"AR23TMM");
	t2.adaugaRemorca(2,"BH67POO");
	System.out.println(t1.equals(t2));
	t1.stergeRemorca("TM69LOL");
	System.out.println(t1);
    }
}
