class Patrat
{
    private double latura;
    private double a;
    public Patrat()
    {
        latura=10;
    }
    public Patrat(double latura)
    {
        this.latura=latura;
    }
    void afiseaza()
    {
        a=latura*latura;
        System.out.println("Patrat "+latura+" Aria "+a);
    }
}

class Main
{
    public static void main(String[] args)
    {
        Patrat p=new Patrat();
        Patrat p1=new Patrat(2);
        Patrat p2=new Patrat(3);
        p.afiseaza();
        p1.afiseaza();
        p2.afiseaza();
    }
}
