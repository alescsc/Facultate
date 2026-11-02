using System;

public struct Coords
{
    public float X { get; set; }
    public float Y { get; set; }
    public Coords(float x, float y)
    {
        X = x;
        Y = y;
    }
    public override string ToString()
    {
        return $"({X}, {Y})";
    }
}
public class Program
{
    public static Coords Mid(Coords p1, Coords p2)
    {
        float midX = (p1.X + p2.X)/2.0f;
        float midY = (p1.Y + p2.Y)/2.0f;
        return new Coords(midX, midY);
    }

    static void Main(string[] args)
    {
        Coords p1 = new Coords(2.0f, 4.0f);
        Coords p2 = new Coords(10.0f, 8.0f);
        Coords mid = Mid(p1, p2);
        Console.WriteLine($"Mijlocul segmentului este: {mid}");
    }
}