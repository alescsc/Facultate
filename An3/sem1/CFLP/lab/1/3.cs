using System;

class Student 
{
    public readonly string name;
    public readonly int year;
    public readonly double grade1;
    public readonly double grade2;
    public readonly double grade3;

    public Student(string n, int y, double g1, double g2, double g3) 
    {
        name = n;
        year = y;
        grade1 = g1;
        grade2 = g2;
        grade3 = g3;
    }

    public double Average 
    {
        get { return (grade1 + grade2 + grade3) / 3.0; }
    }

    public override string ToString() 
    {
        return name + " din anul " + year + " are media " + Average;
    }
}

class Program3 
{
    static void Main() 
    {
        Console.Write("n = ");
        int n = Convert.ToInt32(Console.ReadLine());

        Student[] listaStudenti = new Student[n];

        for (int i = 0; i < n; i++) 
        {
            Console.WriteLine("Studentul " + (i + 1));
            
            Console.Write("Nume: ");
            string n_citit = Console.ReadLine();
            
            Console.Write("An: ");
            int y_citit = Convert.ToInt32(Console.ReadLine());
            
            Console.Write("Nota 1: ");
            double g1_citit = Convert.ToDouble(Console.ReadLine());
            
            Console.Write("Nota 2: ");
            double g2_citit = Convert.ToDouble(Console.ReadLine());
            
            Console.Write("Nota 3: ");
            double g3_citit = Convert.ToDouble(Console.ReadLine());

            listaStudenti[i] = new Student(n_citit, y_citit, g1_citit, g2_citit, g3_citit);
        }

        Student celMaiBun = listaStudenti[0]; 

        for (int i = 1; i < n; i++) 
        {
            if (listaStudenti[i].Average > celMaiBun.Average) 
            {
                celMaiBun = listaStudenti[i]; 
            }
        }

        Console.WriteLine("\nStudentul cu cea mai mare medie este:");
        Console.WriteLine(celMaiBun); 
    }
}