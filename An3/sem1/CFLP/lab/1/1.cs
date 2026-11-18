using System;

public class Program 
{
    public static void Main(string []args)
    {
        int n = int.Parse(Console.ReadLine());
        int Suma = 0;
        for(int i = 0; i < n; i++)
        {
            int nr = int.Parse(Console.ReadLine());
            Suma = Suma + nr;
        }
        Console.WriteLine($"Suma = {Suma}");
    }
}