class Carte
{
    private int nrpag;
    public Carte(int nrpag)
    {
        this.nrpag=nrpag;
    }
    public boolean equals(Object o)
    {
        Carte s=(Carte)o;
        if(o instanceof Carte)
            return (s.nrpag==nrpag);
        else
            return false;
    }

}

class Main
{
    public static void main(String[] args)
    {
    Carte c1=new Carte(22);
    Carte c2=new Carte(21);
    if(c1.equals(c2))
        System.out.println("Egale");
    else
        System.out.println("Nu sunt egale");
    }
}