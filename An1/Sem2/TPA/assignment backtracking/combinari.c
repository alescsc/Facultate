#include <stdio.h>

int valid(int k, int *st)
{
    for(int i = 1; i < k; i++)
        if(st[k] == st[i])
            return 0;
    if(k > 1 && st[k-1] > st[k])
        return 0;
    return 1;
}

int solutie(int k, int p)
{
    return k == p;
}

void tipar(int *st, int p)
{
    for(int i = 1; i <= p; i++)
        printf("%d ", st[i]);
    printf("\n");
}

void back(int k, int n, int p, int *st)
{
    for(int i = 1; i <= n; i++)
    {
        st[k] = i;
        if(valid(k, st)) {
            if(solutie(k, p))
                tipar(st, p);
            else
                back(k+1, n, p, st);
        }
    }
}

int main(void)
{
    int n, p, st[16];
    scanf("%d", &n);
    scanf("%d", &p);
    back(1, n, p, st);
}