#include "utils.h"

 int findElemLin(int v[], unsigned n, int x)
{

	for(int i=0;i<n;i++)
		if(x==v[i])
			return i;
	return -1;
}

 int findElemBin(int v[], unsigned n, int x)
 {
 	int st=0;
 	int dr=n-1;
 	while(st<=dr)
 	{
 		int m=(st+dr)/2;
 		if(v[m]<x)
 			st=m+1;
 		else if(v[m]>x)
 			dr=m-1;
 		else
 			return m;
 	}
 	return -1;
 }

