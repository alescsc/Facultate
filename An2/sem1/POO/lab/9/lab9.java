// lab 9 poo

/*
    INTERFETE

    interface A {
        void m();
    } - putem definii doar metode, toate o sa fie abstracte si publice

    class C implements A {
        void m();
    }

*/

interface Risky
{
    public double getRisk();
}

class Membru
{
    public Membru(int varsta, String nume)
    {
        this.varsta = varsta;
        this.nume = nume;
    }
    private int varsta;
    private String nume;
}

abstract class Proiect implements Risky
{
    protected Membru m[];
    protected int nrMembrii;
    protected String titlu;
    protected String obiectiv;
    protected long fonduri;
    protected int count;
    public void addMember(Membru mem)
    {
        m[count++] = mem;
    }
    public Proiect(String titlu, String obiectiv, long fonduri, int nrMembrii)
    {
        this.titlu = titlu;
        this.obiectiv = obiectiv;
        this.fonduri = fonduri;
        this.nrMembrii = nrMembrii;
    }
}

abstract class com_mil extends Proiect
{
    private String deadLine;
    public com_mil(String titlu, String obiectiv, long fonduri, int nrMembrii, String deadLine)
    {
        super(titlu,obiectiv,fonduri,nrMembrii);
        this.deadLine = deadLine;
    }
}

class comerciale extends com_mil
{
    private long fonduriMarketing = super.fonduri/2;
    private int nrEchipe;
    public comerciale(String titlu, String obiectiv, long fonduri, int nrMembrii, String deadLine, int nrEchipe)
    {
        super(titlu,obiectiv,fonduri,nrMembrii,deadLine);
        this.nrEchipe = nrEchipe;
    }
    public double getRisk()
    {
        return 3 * nrEchipe / nrMembrii / fonduri - fonduriMarketing;
    }
}

class militare extends com_mil
{
    private String parola;
    public militare(String titlu, String obiectiv, long fonduri, int nrMembrii, String deadLine, String parola)
    {
        super(titlu,obiectiv,fonduri,nrMembrii,deadLine);
        this.parola = parola;
    }
    public double getRisk()
    {
        return nrMembrii / parola.length() / fonduri;
    }
}

class openSource extends Proiect
{
    private String mailingList;
    public openSource(String titlu, String obiectiv, long fonduri, int nrMembrii, String mailingList)
    {
        super(titlu,obiectiv,fonduri,nrMembrii);
        this.mailingList = mailingList;
    }
    public double getRisk()
    {
        return nrMembrii / fonduri;
    }
}

class InvestmentCompany
{
    private Proiect proj[] = new Proiect[1000];
    private int count;
    public void addProject(Proiect p)
    {
        proj[count++] = p;
    }

    public Proiect getBestInvestment()
    {
        double min = 10000;
        int index = 0;
        for(int i = 0; i < count; i=i+1)
            if(proj[i].getRisk() < min) {
                min = proj[i].getRisk();
                index = i;
            }
        return proj[index];
    }
    public static void main(String [] args)
    {
        comerciale c = new comerciale("Proiect 1", "Modernizare", 1000000, 12, "1 decembrie", 3);
        InvestmentCompany ic = new InvestmentCompany();
        ic.addProject(c);
        militare m = new militare("Proiect 2", "Cumparare", 100000000, 10, "2036", "1234");
        ic.addProject(m);
        System.out.println(ic.getBestInvestment().titlu);
    }
}
