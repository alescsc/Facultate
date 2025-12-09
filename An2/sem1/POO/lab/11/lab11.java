//lab 11 poo
/*
 * GESTIONAREA ERORILOR (nu mai folosim cuvantul eroare)
 *
 * class nume extends Exception
 *
 * public void ... () throws nume {
 * ...
 * throw new nume();
 * ...
 * }
 *
 *  cand apelam in main bagam in try
 *
 * try {
 *      .........
 * } catch(nume e) {
 *   System.out.println("Eroare!");
 * SAU
 *   e.printStackTrace();
 * } finally {
 *      .... se afiseaza mereu si daca nu avem exceptie
 *      inchidem fisiere aici
 * }
 *
 */

import java.util.Random;
import java.util.Date;


class CoordinateGenerator {
private Random randomGenerator;
public CoordinateGenerator() {
Date now = new Date();
long sec = now.getTime();
randomGenerator = new Random(sec);
}
public int generateX() {
int x = randomGenerator.nextInt(101);
if(x < 5) {
x = 0;
} else if(x > 95) {
x = 100;} else {
x = randomGenerator.nextInt(99) + 1;
}
return x;
}
public int generateY() {
int y = randomGenerator.nextInt(101);
if(y < 5) {
y = 0;
} else if(y > 95) {
y = 50;
} else {
y = randomGenerator.nextInt(49) + 1;
}
return y;
}
}

class Out extends Exception
{}

class Gol extends Exception
{}

class Corner extends Exception
{}

class Minge {
    private int x;
    private int y;

    public Minge(int x, int y)
    {
        this.x = x;
        this.y = y;
    }

    public int getX()
    {
        return x;
    }

    public int getY()
    {
        return y;
    }

    public void suteaza() throws Out, Gol, Corner
    {
        CoordinateGenerator cg = new CoordinateGenerator();
        x = cg.generateX();
        y = cg.generateY();

        if(y == 0 || y == 50)
            throw new Out();

        if((x == 0 || x == 100) && (y >= 20 && y <= 30))
            throw new Gol();

        if((x == 0 || x == 100) && ((y>0 && y<20) || (y>30 && y <50)))
            throw new Corner();
    }
}

class Joc
{
    private String echipa1;
    private String echipa2;
    private int nrGolEchipa1;
    private int nrGolEchipa2;
    private int nrOut;
    private int nrCorner;

    public Joc(String echipa1, String echipa2)
    {
        this.echipa1 = echipa1;
        this.echipa2 = echipa2;
    }

    public String toString()
    {
        return echipa1 + " " + nrGolEchipa1 + " - " + nrGolEchipa2 + " " + echipa2 + "   Outuri:" + nrOut + "   Cornere:" + nrCorner;
    }

    public void simuleaza()
    {
        Minge m = new Minge(50,25);
        for(int i = 0; i < 1000; i = i + 1)
        {
            try {
                m.suteaza();
                System.out.println(echipa1 + " - " + echipa2 + ": Mingea se afla la coordonatele (" + m.getX() + "," + m.getY() + ")");
            } catch(Out e)
            {
                System.out.println("Out!");
                nrOut++;
                m = new Minge(m.getX(), m.getY());
            } catch(Gol e)
            {
                System.out.println("GOOOOOOOOOL!");
                if(m.getX() == 0)
                    nrGolEchipa1 = nrGolEchipa1 + 1;
                else
                    nrGolEchipa2 = nrGolEchipa2 + 1;
            } catch(Corner e)
            {
                System.out.println("Corner!");
                nrCorner++;
                if(m.getY() > 0 && m.getY() < 20 && m.getX() == 0)
                    m = new Minge(0, 0);
                else
                    if(m.getY() > 0 && m.getY() < 20 && m.getX() == 100)
                        m = new Minge(100, 0);
                else
                    if(m.getY() > 30 && m.getY() < 50 && m.getX() == 0)
                        m = new Minge(0, 50);
                else
                    m = new Minge(100, 50);

            }
        }
    }
}

class Main
{
    public static void main(String args[])
    {
        Joc j = new Joc("UTA Arad", "Farul Constanta");
        j.simuleaza();

        Joc j2 = new Joc("FCSB", "PSG");
        j2.simuleaza();
        System.out.println("-----------------------");
        System.out.println(j2);
        System.out.println(j);
    }
}























