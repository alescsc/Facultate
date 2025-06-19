#include <stdio.h>
#define MOD 1000000000

int main(void)
{
	int nr;
	scanf("%d", &nr);
	while(nr)
	{
		int a, b, c, d, e, f, g, h, n;
		scanf("%d %d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h, &n);
		long long x[110], y[110];
		for(int i = 0; i <= n; i++)
		{
			
			if(i == 0)
				{
					x[i] = 1;
					y[i] = 1;
				}
			else
				{
					long long xa, yb, yc;
					long long ye, xf, xg;
					if(i - a >= 0)
						xa = x[i-a];
					else
						xa = 1;
					if(i - b >= 0)
						yb = y[i-b];
					else
						yb = 1;
					if(i - c >= 0)
						yc = y[i-c];
					else
						yc = 1;
					x[i] = (xa + yb + yc + (long long)(i*d))%MOD;
					if(i - e >= 0)
						ye = y[i-e];
					else
						ye = 1;
					if(i - f >= 0)
						xf = x[i-f];
					else
						xf = 1;
					if(i - g >= 0)
						xg = x[i-g];
					else
						xg = 1;
					y[i] = (ye + xf + xg + (long long)(i*h))%MOD;
				}
		}
		printf("%lld %lld\n", x[n], y[n]);
		nr--;
	}
	return 0;
}