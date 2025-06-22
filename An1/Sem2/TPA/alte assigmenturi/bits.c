#include <stdio.h>

#define SIZE 125

int main(void)
{
    int n, x;

    unsigned char v[SIZE] = {0};

    printf("n=");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);

        if(x >= 0 && x <= 1000)
            v[x/8] = v[x/8] | (1 << (x % 8));
    }

    printf("Numerele introduse sunt:\n");

    for(int i = 0; i <= 1000; i++)
    {
        if((v[i/8] & (1 << (i % 8))) != 0)
            printf("%d\n", i);
    }
    return 0;
}