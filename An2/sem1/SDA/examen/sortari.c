void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void quicksort(tip_elem a[], int prim, int ultim)
{
    if(prim >= ultim)
        return;

    int stanga = prim + 1;
    int dreapta = ultim;

    swap(&a[prim], &a[(prim + ultim)/2]);

    tip_elem pivot = a[prim];

    while(stanga <= dreapta)
    {
        while(stanga <= ultim && a[stanga].cheie < pivot.cheie)
            stanga++;
                                    //  < < - cresc, > > - descresc
        while(dreapta >= prim && pivot.cheie < a[dreapta].cheie)
            dreapta--;

        if(stanga < dreapta)
            swap(&a[stanga++], &a[dreapta--]);
        else
            stanga++;
    }

    swap(&a[dreapta], &a[prim]);

    if(prim < dreapta - 1)
        quicksort(a, prim, dreapta - 1);
    if(dreapta + 1 < ultim)
        quicksort(a, dreapta + 1, ultim);
} // se foloseste mereu pt sortare

void quicksort2(tip_elem a[], int prim, int ultim)
{
    int stanga = prim;
    int dreapta = ultim;
    while(stanga <= dreapta)
    {
        while(stanga <= ultim && a[stanga].cheie < 40)
            stanga++;
        while(dreapta >= prim && a[dreapta].cheie > 40)
            dreapta--;
        if(stanga < dreapta)
            swap(&a[stanga++], &a[dreapta--]);
        else
            stanga++;
    }
} // sortare punem elem sub 40 in fata, peste in spate

void partial_sort(tip_elem a[], int n, int k)
{
    int min;
    for(int i = 0; i < k; i++)
    {
        min = i;
        for(int j = i + 1; j < n; j++)
            if(a[min].cheie > a[j].cheie)
                min = j;
        swap(&a[min], &a[i]);
    }
} // sortam doar pimele k elemente in ordine crescatoare