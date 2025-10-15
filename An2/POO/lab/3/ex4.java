
class Piramida
{
    private int n;
    private int i=0,j=0;
    public Piramida(int n)
    {
        this.n=n;
    }
    void afisare1(int i)
    {
        for(j=0;j<i;j++)
            System.out.print(i+" ");
        System.out.println();
    }

    void afisare()
    {
        for(i=n;i>0;i--)
            {
                afisare1(i);
            }
    }
}

class Main
{
    public static void main(String[] args)
    {
        Piramida p=new Piramida(4);
        p.afisare();
    }
}

