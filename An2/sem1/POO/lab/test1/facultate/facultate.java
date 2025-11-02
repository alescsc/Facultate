class Student
{
	private String nume;
	private int nr_matricol;
	private double medie;

	public Student(String nume, int nr_matricol, double medie)
	{
		this.nume = nume;
		this.nr_matricol = nr_matricol;
		this.medie = medie;
	}

	public int getNr_Matricol()
	{
		return nr_matricol;
	}

	public String getNume()
	{
		return nume;
	}

	public double getMedie()
	{
		return medie;
	}

}

class Curs
{
	private Student[] st = new Student[100];
	private int nrst;
	public void adaugaStudent(Student student)
	{
		int ok = 1;
		for(int i = 0; i < nrst; i++)
			if(student.getNr_Matricol() == st[i].getNr_Matricol())
				ok = 0;
		if(ok == 1)
		{
			nrst++;
			st[nrst-1] = student;
		}
	}

	public void afiseazaStudenti()
	{
		for(int i = 0; i < nrst; i++)
			System.out.println("Nume: " + st[i].getNume() + ", Nr Matricol: " + st[i].getNr_Matricol() + ", Medie: " + st[i].getMedie());
	}

	public double medieGenerala()
	{
		double s = 0;
		for(int i = 0; i < nrst; i++)
			s = s + st[i].getMedie();
		return s/nrst;
	}

	public String studentiCuMediaPeste(double medieMinima)
	{
		String sir = "";
		for(int i = 0; i < nrst; i++)
		{
			if(st[i].getMedie() > medieMinima)
				sir = sir + st[i].getNume();
		}
		return sir;
	}

}

class Main
{
	public static void main(String[] argv)
	{	
		Curs c1 = new Curs();

		Student st1 = new Student("Dori", 123, 10);
		Student st2 = new Student("Alex", 124, 5);

		c1.adaugaStudent(st1);
		c1.adaugaStudent(st2);

		c1.afiseazaStudenti();

		System.out.println("Medie generala: " + c1.medieGenerala());

		System.out.println("Studenti cu media peste 7: " + c1.studentiCuMediaPeste(7));

	}
}

