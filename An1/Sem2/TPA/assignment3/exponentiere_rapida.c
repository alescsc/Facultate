#include <stdio.h>
#include <stdlib.h>

#define MOD 1999999973

long long putere(long long x,long long n)
{

		if(n == 0)
			return 1;
		else
			if(n % 2 == 0)
				return putere((x*x) % MOD, n/2);
			else
				return (x * putere((x*x) % MOD, (n-1)/2)) % MOD;
}

int main(void)
{
	FILE *f = NULL, *out = NULL;

	if((f = fopen("lgput.in","r")) == NULL)
	{
		perror(NULL);
		exit(-1);
	}

	if((out = fopen("lgput.out","w")) == NULL)
	{
		perror(NULL);
		exit(-1);
	}

	long long n, p;
	fscanf(f,"%lld %lld",&n, &p);
	fprintf(out, "%lld", putere(n, p));

	if(fclose(f) != 0)
	{
		perror(NULL);
		exit(-1);
	}

	if(fclose(out) != 0)
	{
		perror(NULL);
		exit(-1);
	}
	return 0;
}