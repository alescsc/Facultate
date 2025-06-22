#include <stdio.h>

int valid(int k, int *st)
{
    for(int i = 1; i < k; i++)
        if(st[k] == st[i])
            return 0;
    return 1;
}

int solutie(int k, int n)
{
    return k == n;
}

void tipar(int *st, int n)
{
    for(int i = 1; i <= n; i++)
        printf("%d ", st[i]);
    printf("\n");
}

void back(int k, int n, int *st)
{
    for(int i = 1; i <= n; i++)
    {
        st[k] = i;
        if(valid(k, st))
            if(solutie(k, n))
                tipar(st, n);
        else
            back(k+1, n, st);
    }
}

int main(void)
{
    int n, st[20];
    scanf("%d", &n);
    back(1, n, st);
    return 0;
}