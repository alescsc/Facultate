void parcurgere_adancime(int nod, int n, int a[NMAX][NMAX], int vizitat[NMAX])
{
	vizitat[nod] = 1;
	printf("%d ", nod);
	for(int i = 1; i <= n; i++)
		if(vizitat[i] == 0 && a[i][nod] != 0)
			parcurgere_adancime(i, n, a, vizitat);
}

void parcurgere_cuprindere(int nod, int n, int a[NMAX][NMAX])
{
	int vizitat[NMAX] = {0};
	int coada[NMAX] = {0};
	int prim = 0, ultim = 0;

	coada[prim] = nod;
	vizitat[nod] = 1;

	while(prim <= ultim)
	{
		int nod_curent = coada[prim];
		prim++;
		printf("%d ", nod_curent);
		for(int i = 1; i <= n; i++)
			if(vizitat[i] == 0 && a[i][nod_curent] != 0)
			{
				ultim++;
				coada[ultim] = i;
				vizitat[i] = 1;
			}
	}
	printf("\n");
}

int CC = 0;
int vizitat[NMAX] = {0};
for(int i = 1; i <= n; i++)
	if(vizitat[i] == 0)
	{
		CC++;
		printf("Componenta conexa %d) ", CC);
		parcurgere_adancime(i, n, a, vizitat);
	}

printf("Nr. total componente conexe: %d", CC);

void prim(int n, int a[NMAX][NMAX])
{
	int vizitat[NMAX] = {0};
	int cost_total = 0;
	vizitat[1] = 1;
	for(int pas = 1; pas <= n - 1; pas++)
	{
		int min = 99999999;
		int mini = -1, minj = -1;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(a[i][j] != 0 && a[i][j] < min && vizitat[i] != 0 && vizitat[j] == 0)
				{
					min = a[i][j];
					mini = i;
					minj = j;
				}
		if(mini != -1 && minj != -1)
		{
			cost_total = cost_total + min;
			printf("Muchia (%d - %d), cost: %d", mini, minj, min);
			vizitat[minj] = 1;
		}
	}
	printf("Cost total: %d", cost_total);
}

void kruskal(int n, int a[NMAX][NMAX])
{
	int vizitat[NMAX] = {0};
	int cost_total = 0;

	for(int i = 1; i <= n; i++)
		vizitat[i] = i;

	for(int pas = 1; pas <= n - 1; pas++)
	{
		int min = 999999999;
		int mini = -1, minj = -1;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(vizitat[i] != vizitat[j] && a[i][j] < min && a[i][j] != 0)
				{
					min = a[i][j];
					mini = i;
					minj = j;
				}
		if(mini != -1 && minj != -1)
		{
			cost_total = cost_total + min;

			printf("Muchia (%d - %d), cost: %d", mini, minj, min);

			int pred = vizitat[minj];
			int cur = vizitat[mini];

			for(int i = 1; i <= n; i++)
				if(vizitat[i] == pred)
					vizitat[i] = cur;
		}
	}
	printf("Cost total: %d", cost_total);
}

void djikstra(int start, int n, int a[NMAX][NMAX])
{
	int dist[NMAX] = {0};
	int vizitat[NMAX] = {0};
	int INF = 999999999;

	for(int i = 1; i <= n; i++)
		dist[i] = INF;

	dist[start] = 0;

	for(int pas = 1; pas <= n - 1; pas++)
	{
		int min = INF;
		int u = -1;
		for(int i = 1; i <= n; i++)
			if(dist[i] < min && vizitat[i] == 0)
			{
				min = dist[i];
				u = i;
			}
		if(u == -1)
			break;

		vizitat[u] = 1;
		for(int v = 1; v <= n; v++)
			if(a[u][v] != 0 && vizitat[v] == 0 && dist[u] + a[u][v] < dist[v])
				dist[v]	= dist[u] + a[u][v];
	}

	for(int i = 1; i <= n; i++)
		if(dist[i] == INF)
			printf("Distanta de la %d la %d: INF", start, i);
		else
			printf("Distanta de la %d la %d: INF", start, i, dist[i]);

}