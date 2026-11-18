using System;
using System.Runtime.InteropServices;

public class Program
{
    public static void Main(string []args)
    {
        double a = double.Parse(Console.ReadLine());
        double b = double.Parse(Console.ReadLine());
        double c = double.Parse(Console.ReadLine());

        if(a == 0)
        {
            if(b == 0)
                Console.WriteLine("Nu exista solutii!");
            else
                Console.WriteLine($"x = {-c/b}");
            return;
        }

        double delta = b*b - 4*a*c;
        if(delta < 0)
        {
            Console.WriteLine("Nu exista solutii reale!");
            return;
        }
        else if(delta == 0)
        {
            Console.WriteLine($"x1 = x2 = {-b/(2*a)}");
            return;
        }
        else
        {
            Console.WriteLine($"x1 = {(-b + Math.Sqrt(delta))/(2*a)}");
            Console.WriteLine($"x2 = {(-b - Math.Sqrt(delta))/(2*a)}");
        }
    }
}