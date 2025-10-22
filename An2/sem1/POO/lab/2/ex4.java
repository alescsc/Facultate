class sertar
{
    private double l, L, h;
    public sertar(double l, double L, double h)
    {
        this.l=l;
        this.L=L;
        this.h=h;
    }

    void tipareste()
    {
        System.out.println("Sertar"+" "+l+" "+L+" "+h);
    }
}
class birou
{
    void tipareste(sertar s, sertar s2)
    {
        s.tipareste();
        System.out.println(" ");
        s2.tipareste();
    }
}

class main
{
    static public void main(String argv[])
    {
        sertar s=new sertar(23.3,34.5,40);
        sertar s2=new sertar(12.5,30,34.5);
        birou b=new birou();
        b.tipareste(s,s2);
    }
}
