class Complex {
    private double re, im;
    private static int cnt = 0;

    public Complex(double re, double im)
    {
	this.re = re;
	this.im = im;
    }

    public double getModul()
    {
	double modul = re*re + im*im;
	modul = Math.sqrt(modul);
	return modul;
    }

    public void afisare()
    {
	cnt++;
	System.out.println(re + "+" + "i*" + im);
    }

    public Complex suma(Complex nr)
    {
	Complex n = new Complex(0,0);
	n.re = re + nr.re;
	n.im = im + nr.im;
	return n;
    }

    public void nrAfisari()
    {
	System.out.println("S-au afisat " + cnt + " numere complexe");
    }
}

class ClientComplex {
    public static void main(String[] args) {
	Complex n1 = new Complex(2,3);
	Complex n2 = new Complex(7,9);
        n1.afisare();
	n2.afisare();
	System.out.println(n1.getModul());
	Complex n3 = n1.suma(n2);
	n3.afisare();
	n1.nrAfisari();
    }
}
