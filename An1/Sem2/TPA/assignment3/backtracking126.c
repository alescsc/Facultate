#include <stdio.h>

int v[100], c, b, g, a;

int solutie(int k, int n)
{
	if(k != n)
		return 0;
	int sc = 0, sb = 0, sg = 0, sa = 0;
	for(int i = 0; i < n; i++)
		if(v[i] == 0) sc++;
		else if(v[i] == 1) sb++;
		else if(v[i] == 2) sg++;
		else if(v[i] == 3) sa++;
	if(sc != c || sb != b || sg != g || sa != a)
		return 0;
	return 1;
}

int valid(int k)
{
	if(k == 0)
		return 1;

	if(v[k] == 0 && v[k-1] == 3)
		return 0;
	if(v[k] == 1 && (v[k-1] == 2 || v[k-1] == 3))
		return 0;
	if(v[k] == 2 && v[k-1] == 1)
		return 0;
	if(v[k] == 3 && (v[k-1] == 0 || v[k-1] == 1))
		return 0;
	return 1;
}

void tipar(int n)
{
	for(int i = 0; i < n; i++)
	{
		if(v[i] == 0)
			printf("c ");
		if(v[i] == 1)
			printf("b ");
		if(v[i] == 2)
			printf("g ");
		if(v[i] == 3)
			printf("a ");
	}
	printf("\n");
}

void back(int k, int n)
{
	for(int i = 0; i < 4; i++)
	{
		v[k] = i;
		if(valid(k))	
		{
			if(solutie(k+1,n))
				tipar(n);
			else
				back(k+1, n);
		}
	}
}

int main(void)
{
	scanf("%d %d %d %d", &c, &b, &g, &a);
	int n = c + b + g + a;
	back(0, n);
	return 0;
}