#include <stdio.h>

int v[100];

int bsearch(int x, int st, int dr)
{
	int m=(st+dr)/2;
	if(st>dr)
		return 0;
	if(x==v[m])
		return 1;
	if(x<v[m])
	{
		return bsearch(x,st,m-1);
	}
	if(x>v[m])
	{
		return bsearch(x,m+1,dr);
	}
}	

int main(void)
{
	int n;
	printf("n=");
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&v[i]);
	int x;
	printf("x=");
	scanf("%d",&x);
	if(bsearch(x,1,n-1))
		printf("gasit!");
	else
		printf("nu este in vector!");
	return 0;
}