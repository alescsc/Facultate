using System;

class Program1 
{
    static void Main() 
    {
        Console.Write("n = ");
        int n = Convert.ToInt32(Console.ReadLine());

        int suma = 0; 

        for (int i = 0; i < n; i++) 
        {
            int numar = Convert.ToInt32(Console.ReadLine()); 
            
            suma = suma + numar; 
        }

        Console.WriteLine("Suma = " + suma);
    }
}