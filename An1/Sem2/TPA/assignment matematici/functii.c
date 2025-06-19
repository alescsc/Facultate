#include <stdio.h>
#include <stdlib.h>

#define MOD 30103
#define MAXN 10001

int fact[MAXN], inv_fact[MAXN];

int putere(int b, int e)
{
	int r = 1;
	while(e)
	{
		if(e % 2)
			r = (r*b)%MOD;
		b = (b*b)%MOD;
		e = e/2;
	}
	return r;
}

void factoriale()
{
	fact[0] = 1;
	for(int i = 1; i < MAXN; i++)
		fact[i] = (fact[i-1]*i)%MOD;
	for(int i = 0; i < MAXN; i++)
		inv_fact[i] = putere(fact[i], MOD-2);
}

int combinari(int n, int k)
{
	if(k < 0 || k > n)
		return 0;
	return (((fact[n] * inv_fact[k])%MOD)*inv_fact[n - k])%MOD;
}


int main(void)
{
	int n, suma;
	FILE *f = NULL, *o = NULL;
	if((f = fopen("functii.in", "r")) == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	if((o = fopen("functii.out", "w")) == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	fscanf(f,"%d %d", &n, &suma);
	factoriale();
	int total = (combinari(n, suma)*putere(2, suma))%MOD;
	if(suma == n)
		total = (total - putere(2,n) + MOD)%MOD;
	total = (total - combinari(n, suma) + MOD)%MOD;
	total = (total - combinari(n, suma) + MOD)%MOD;
	if(suma == 0)
		total = (total + 1)%MOD;
	fprintf(o,"%d\n", total);
	if(fclose(f) == -1)
	{
		perror(NULL);
		exit(-1);
	}
	if(fclose(o) == -1)
	{
		perror(NULL);
		exit(-1);
	}
	return 0;
}