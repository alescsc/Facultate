#include <stdio.h>

long fib(int n)
{
	if(n==0)
		return 0;
	else
		if(n==1)
			return 1;
		else
			return fib(n-2)+fib(n-1);
}

double phi(int n)
{
	return (double)fib(n+1)/fib(n);
}

int main(void)
{
	int n;
	printf("n=");
	scanf("%d",&n);
	printf("%lf",phi(n));
	return 0;
}