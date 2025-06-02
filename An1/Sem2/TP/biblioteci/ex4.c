#include <stdio.h>
#include "utils.h"

int main(void)
{
	int n=4, v1[]={-2,23,10,2}, v2[]={1,2,3,4}, x;
	printf("x=");
	scanf("%d",&x);
	printf("%d\n", findElemLin(v1,n,x));
	printf("%d\n", findElemBin(v2,n,x));
	return 0;
}