#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	double x, y;
} punct;

int compar(const void *a, const void *b)
{
	punct* p = (punct*)a;
	punct* q = (punct*)b;
	if (p->x < q->x)
        return -1;
    else if (p->x > q->x)
        return 1;
    else if (p->y < q->y)
        return -1;
    else if (p->y > q->y)
        return 1;
    else
        return 0;
}

double produs(punct o, punct a, punct b)
{
	return (a.x - o.x)*(b.y - o.y) - (a.y - o.y)*(b.x - o.x);
}

int formeaza_poligon(punct* p, int n, punct* h)
{
	qsort(p, n, sizeof(punct), compar);
	int k = 0;
	for(int i = 0; i < n; i++)
	{
		while(k >= 2 && produs(h[k-2], h[k-1], p[i]) <= 0)
			k--;
		h[k++] = p[i];
	}
	int t = k + 1;
	for(int i = n - 2; i >= 0; i--)
	{
		while(k >= t && produs(h[k-2], h[k-1], p[i]) <= 0)
			k--;
		h[k++] = p[i];
	}
	return k-1;
}

int main(void)
{
	FILE *f = NULL;
	FILE *o = NULL;
	if((f = fopen("infasuratoare.in", "r")) == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	if((o = fopen("infasuratoare.out", "w")) == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	int n;
	fscanf(f, "%d", &n);
	punct* p = malloc(n*sizeof(punct));
	for(int i = 0; i < n; i++)
		fscanf(f, "%lf %lf", &p[i].x, &p[i].y);
	punct* h = malloc(2*n*sizeof(punct));
	int nr_pct = formeaza_poligon(p, n, h);
	fprintf(o, "%d\n", nr_pct);
	for(int i = 0; i < nr_pct; i++)
		fprintf(o, "%.6lf %.6lf\n", h[i].x, h[i].y);
	free(p); free(h);
	if(fclose(f) != 0)
	{
		perror(NULL);
		exit(-1);
	}
	if(fclose(o) != 0)
	{
		perror(NULL);
		exit(-1);
	}
	return 0;
}