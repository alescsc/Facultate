#include <stdio.h>

long fact(int n)
{
	if(n==1 || n==0)
		return 1;
	else
		return n*fact(n-1);
}

long putere(int n, int x)
{
	if(x==1)
		return n;
	else
		return n*putere(n,x-1);
}

double taylor(int n, int x)
{
	if(n==1)
		return 1;
	else
		return (putere(x,n)/fact(n))+taylor(n-1,x);
}

int main(void)
{
	int n;
	printf("n=");
	scanf("%d",&n);
	int x;
	printf("x=");
	scanf("%d",&x);
	printf("%f",taylor(n,x));
	return 0;
}