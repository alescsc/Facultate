using System;

public delegate float MyDelegate(float x);

public class Program
{
    public static float FGX(MyDelegate del1, MyDelegate del2, float x)
    {
        return del1(del2(x));
    }

    public static float f(float x)
    {
        return x * 3;
    }

    public static float g(float x)
    {
        return x - 2;
    }

    static void Main(string[] args)
    {
        MyDelegate d1 = f;
        MyDelegate d2 = g;
        float val = 5.0f;
        float rez = FGX(d1, d2, val);
        Console.WriteLine($"FGX pentru x = {val} este: {rez}");
    }
}