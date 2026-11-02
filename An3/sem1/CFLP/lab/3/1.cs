using System;

public class Program
{
    public static void Swap(ref int a, ref int b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    static void Main(string[] args)
    {
        int x = 15;
        int y = 30;
        Swap(ref x, ref y);
        Console.WriteLine($"x={x}, y={y}");
    }
}