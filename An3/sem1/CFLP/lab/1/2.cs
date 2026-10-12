using System;

class Program2 
{
    static void Main() 
    {
        Console.Write("a = ");
        double a = Convert.ToDouble(Console.ReadLine());
        
        Console.Write("b = ");
        double b = Convert.ToDouble(Console.ReadLine());
        
        Console.Write("c = ");
        double c = Convert.ToDouble(Console.ReadLine());

        double delta = (b * b) - (4 * a * c);

        if (delta > 0) 
        {
            double x1 = (-b + Math.Sqrt(delta)) / (2 * a);
            double x2 = (-b - Math.Sqrt(delta)) / (2 * a);
            Console.WriteLine("x1 = " + x1);
            Console.WriteLine("x2 = " + x2);
        } 
        else if (delta == 0) 
        {
            double x = -b / (2 * a);
            Console.WriteLine("Avem o singura solutie: x = " + x);
        } 
        else 
        {
            Console.WriteLine("Ecuatia nu are solutii reale.");
        }
    }
}