void parcurgere_cuprindere(int nod, int n, int a[NMAX][NMAX])
{
	int coada[NMAX] = {0};
	int vizitat[NMAX] = {0};

	int prim = 0, ultim = 0;

	coada[ultim] = nod;
	vizitat[nod] = 1;

	while(prim <= ultim)
	{
		int nod_curent = coada[prim];
		prim++;

		printf("%d ", nod_curent);
		for(int i = 1; i <= n; i++)
		{
			if(vizitat[i] == 0 && a[nod_curent][i] != 0)
			{
				ultim++;
				coada[ultim] = i;
				vizitat[i] = 1;
			}
		}
	}
}

void parcugere_adancime(int nod, int n, int a[NMAX][NMAX], int vizitat[NMAX])
{
	vizitat[nod] = 1;
	printf("%d ");
	for(int i = 1; i <= n; i++)
		if(vizitat[i] == 0 && a[nod][i] != 0)
			parcugere_adancime(i, n, a, vizitat);
}

// componente conexe

int CC = 0;

for(int i = 1; i <= n; i++)
{
	if(vizitat[i] == 0)
	{
		CC++;
		printf("Componenta conexa nr %d: \n", CC);
		parcugere_adancime(i, n, a, vizitat);
	}
}

printf("Nr CC: %d\n" CC);

// arbore de acoperire

void arbore_acoperire(int nod, int n, int a[NMAX][NMAX], int vizitat[NMAX])
{
	vizitat[nod] = 1;
	for(int i = 1; i <= n; i++)
		if(vizitat[i] == 0 && a[nod][i] != 0)
		{
			printf("%d - %d", nod, i);
			arbore_acoperire(i, n, a, vizitat);
		}
}
