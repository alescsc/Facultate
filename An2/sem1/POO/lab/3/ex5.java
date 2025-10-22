class Suma
{
    private int a,b,c,d;
    static private int s;

    public Suma(int a, int b, int c, int d)
    {
        this.a=a;
        this.b=b;
        this.c=c;
        this.d=d;
    }

    public static int suma(int a, int b)
    {
        return a+b;
    }

    public static int suma(int a, int b, int c)
    {
        return suma(a,b)+c;
    }

    public static int suma(int a, int b, int c, int d)
    {
        return suma(a,b,c)+d;
    }
    void afiseaza()
    {
        System.out.println(suma(a,b,c,d));
    }
}

class Main
{
    public static void main(String[] args)
    {
        Suma sum=new Suma(1,2,3,4);
        sum.afiseaza();
    }
}
