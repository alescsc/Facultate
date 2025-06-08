#include <stdio.h>

int main(void)
{
	int n, Gmax, G[1001], V[1001], dp[100001] = {0};
	scanf("%d %d", &n, &Gmax);
	for(int i = 0; i < n; i++)
	{
		scanf("%d %d", &G[i], &V[i]);
	}
	for(int i = 0; i < n; i++)
		for(int j = Gmax; j >= G[i]; j--)
			if(dp[j] < dp[j - G[i]] + V[i])
				dp[j] = dp[j - G[i]] + V[i];
	printf("%d\n", dp[Gmax]);	
	return 0;
}