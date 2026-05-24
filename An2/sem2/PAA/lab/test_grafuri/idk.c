void parcurgere_adancime(int nod, int n, int a[MAX_NOD][MAX_NOD], int vizitat[])
{
	vizitat[nod] = 1;
	printf("%d ", nod);
	for(int i = 1; i <= n; i++)
		if(vizitat[i] == 0 && a[nod][i] != 0)
		{
			parcurgere_adancime(i, n, a, vizitat);
		}
}

// COMPONENTE CONEXE:

int vizitat[MAX_NOD] = {0};

int CC = 0;

for(int i = 1; i <= n; i++)
{
	if(vizitat[i] == 0)
	{
		CC++;
		printf("Componenta conexa %d: \n", CC);
		parcurgere_adancime(i, n, a, vizitat);
	}
}

printf("Nr total compoente conexe %d.", CC);

// ARBORE DE ACOPERIRE

void arbore_acoperire(int nod, int n, int a[MAX_NOD][MAX_NOD], int vizitat[])
{
	vizitat[nod] = 1;
	for(int i = 1; i <= n; i++)
		if(vizitat[i] == 0 && a[nod][i] != 0)
		{
			printf("%d - %d, ", nod, i);
			arbore_acoperire(i, n, a, vizitat);
		}
}

// PARCURGERE CUPRINDERE

void parcurgere_cuprindere(int nod, int n, int a[MAX_NOD][MAX_NOD], int vizitat[])
{
	// sau pun vizitat aici
	int coada[MAX_NOD] = {0};
	int prim, ultim = 0;

	coada[ultim] = nod;
	vizitat[nod] = 1;

	while(prim <= ultim)
	{
		int nod_curent = coada[prim];
		prim++;

		for(int i = 1; i <= n; i++)
		{
			if(vizitat[i] == 0 && a[nod_curent] != 0)
			{
				vizitat[i] = 1;
				ultim++;
				coada[ultim] = i;
			}
		}
	}
}