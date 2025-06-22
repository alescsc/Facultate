#include <stdio.h>
#include <math.h>

int valid(int k, int *st)
{
    for(int i = 1; i < k; i++)
        if(st[k] == st[i] || abs(k - i) == abs(st[k] - st[i]))
            return 0;
    return 1;
}

int solutie(int k, int n)
{
    return k == n;
}

void back(int k, int *total, int n, int *st)
{
    for(int i = 1; i <= n; i++)
    {
        st[k] = i;
        if(valid(k, st))
            if(solutie(k, n))
                (*total)++;
            else
                back(k+1, total, n, st);
    }
}

int main(void)
{
    int n, st[25], total = 0;
    scanf("%d", &n);
    back(1, &total, n, st);
    printf("%d", total);
    return 0;
}