import java.io.*;
import java.util.Random;

class Telefon
{
    private String nume;
    private String[] agenda = new String[100];
    private int[] contor = new int[100];
    private int n = 0;
    public boolean apeleaza(Telefon t)
    {
	if(n == 100)
	    return false;
	else
	    {
		for(int i = 0; i < n; i++)
		    if(this.agenda[i].equals(t.nume))
			{
			    this.contor[i]++;
			    return true;
			}
		n++;
		this.agenda[n-1] = t.nume;
		this.contor[n-1] = 1;
		return true;
	    }
    }
    public int numarDeApeluri(String s)
    {
	for(int i = 0; i < n; i++)
	    if(this.agenda[i].equals(s))
		return this.contor[i];
	return -1;
    }

    public String toString()
    {
	String s = new String();
	s = s + nume;
	for(int i = 0; i < n; i++)
	    s = s + " " + agenda[i];
	return s;
    }

    public void setName(String nume)
    {
        this.nume = nume;
    }
}

class Main
{
    public static void main(String[] args)
    {
        try
	    {
		InputStreamReader isr = new InputStreamReader(System.in);
		 BufferedReader bf = new BufferedReader(isr);
		 int n = Integer.parseInt(bf.readLine());
		 Telefon tel[] = new Telefon[n];
		 for(int i = 0; i < n; i++)
		     {
			 tel[i] = new Telefon();
			 tel[i].setName(bf.readLine());
		     }
		 
		 int A = Integer.parseInt(bf.readLine());
		 for(int i = 0; i <= A; i++)
		     {
			 Random generator = new Random();
			 System.out.println(tel[generator.nextInt(n)].apeleaza(tel[generator.nextInt(n)]));
		     }
		 for(int i = 0; i < n; i++)
		     System.out.println(tel[i]);
	    }
	catch(IOException e)
	    {
		System.out.println("Eroare la citire!");
	    }
    }
}
