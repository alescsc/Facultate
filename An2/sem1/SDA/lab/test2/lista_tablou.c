#include <stdio.h>
#include <stdlib.h>

#define LMAX 100

typedef int Nod;

typedef struct Lista {
	Nod tab[LMAX];
	int ultim;
} Lista;

void initializare(Lista *l)
{
	l->ultim = 0;
}

int adauga_elem(Lista *l, Nod valoare)
{
	if(l->ultim >= LMAX)
		return 0;
	l->tab[l->ultim] = valoare;
	l->ultim++;
	return 1;
}

int cauta_elem(Lista *l, Nod valoare)
{
	for(int i = 0; i < l->ultim; i++)
		if(l->tab[i] == valoare)
			return i;
	return -1;
}

int sterge_poz(Lista *l, int poz)
{
	for(int i = poz; i < l->ultim - 1; i++)
		l->tab[i] = l->tab[i + 1];
	l->ultim--;
	return 1;
}

int sterge_val(Lista *l, Nod valoare)
{
	int k;
	for(int i = 0; i < l->ultim; i++)
		if(l->tab[i] == valoare)
			k = i;
	for(int i = k; i < l->ultim - 1; i++)
		l->tab[i] = l->tab[i + 1];
	l->ultim--;
	return 1;
}

void afiseaza_lista(Lista *l)
{
	for(int i = 0; i < l->ultim; i++)
		printf("%d ", l->tab[i]);
}


int main(void)
{
	Lista l;

	initializare(&l);

	adauga_elem(&l, 1);
	adauga_elem(&l, 2);
	adauga_elem(&l, 3);
	adauga_elem(&l, 4);

	afiseaza_lista(&l);

	printf("\n");
	int i = cauta_elem(&l, 3);
	printf("%d\n", i);

	sterge_poz(&l, i);

	afiseaza_lista(&l);
	return 0;
}