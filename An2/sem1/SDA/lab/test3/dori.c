#include <stdio.h>


//PERMUTARI

int valid(int k)
{
	for(int i = 1; i < k; i++)
		if(st[k] == st[i])
			return 0;
	return 1;
}

int solutie(int k)
{
	return k == n;
}

void tipar()
{
	for(int i = 1; i <= n; i++)
		printf("%d ", st[i]);
}

void back(int k)
{
	for(int i = 1; i <= n; i++)
	{
		st[k] = i;
		if(valid(k))
			if(solutie(k))
				tipar()
		else
			back(k + 1);
	}
}

int main(void)
{
	return 0;
}