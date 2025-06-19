#include <stdio.h>

int a[100005];

int main(void)
{
	int n, q;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &q);
	while(q)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		if(a[x]%2 == 1)
			printf("Odd\n");
		else
		{
			if(x == n || a[x+1] != 0)
				printf("Even\n");
			else
				printf("Odd\n");
		}
	}
	return 0;
}