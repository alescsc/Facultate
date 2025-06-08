#include <stdio.h>

int n, Gmax, G[1001], V[1001], profit = 0;

void back(int k, int greutate, int valoare)
{
	if(k == n)
	{
		if(greutate <= Gmax && valoare > profit)
			profit = valoare;
		return;
	}
	back(k+1, greutate, valoare);
	if(greutate + G[k] <= Gmax)
		back(k+1, greutate+G[k], valoare+V[k]);
}

int main(void)
{	
	scanf("%d %Gmax", &n, &Gmax);
	for(int i = 0; i < n; i++)
		scanf("%d %d", &G[i], &V[i]);
	back(0, 0, 0);
	printf("%d\n", profit);
	return 0;
}