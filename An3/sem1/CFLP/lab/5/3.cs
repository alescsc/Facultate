using System;
using System.Collections.Generic;

public class Stack<T>
{
    private List<T> elemente = new List<T>();

    public void Push(T item)
    {
        elemente.Add(item);
    }

    public T Pop()
    {
        if(elemente.Count == 0)
        {
            throw new InvalidOperationException("Eroare: Stiva e goala!");
        }
        int lastIndex = elemente.Count - 1;
        T val = elemente[lastIndex];
        elemente.RemoveAt(lastIndex);
        return val;
    }

    public bool TryPop(out T item)
    {
        if(elemente.Count == 0)
        {
            item = default(T);
            return false;
        }

        int ultimIndex = elemente.Count - 1;
        item = elemente[ultimIndex];
        elemente.RemoveAt(ultimIndex);
        return true;
    }

    public T Peek()
    {
        if(elemente.Count == 0)
            throw new InvalidOperationException("Eroare: Stiva e goala!");
        return elemente[elemente.Count - 1];
    }
}

public class Program
{
    static void Main(string[] args)
    {
        Stack<int> stiva = new Stack<int>();
        stiva.Push(100);
        stiva.Push(200);

        if(stiva.TryPop(out int scos))
            Console.WriteLine("Am scos nr: " + scos);
        Console.WriteLine("A ramas in varf: " + stiva.Peek());
    }
}