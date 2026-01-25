#include <stdio.h>
#include <stdlib.h>

typedef struct Nod
{
	int val;
	struct Nod* prev;
	struct Nod* next;
} Nod;

typedef struct Lista
{
	Nod* prim;
	Nod* ultim;
	int size;
} Lista;

Nod* creare(int val)
{
	Nod* nou = (Nod*)malloc(sizeof(Nod));

	nou->val = val;
	nou->next = NULL;
	nou->prev = NULL;

	return nou;
}

void adauga(Lista* lista, int val)
{
	Nod* nou = creare(val);

	if(lista->prim == NULL)
	{
		lista->prim = nou;
		lista->ultim = nou;
	}
	else
	{
		lista->ultim->next = nou;
		nou->prev = lista->ultim;
		lista->ultim = nou;
	}

	lista->size++;
}

void afiseaza(Lista* lista)
{
	Nod* aux = lista->prim;

	printf("Lista: ");

	while(aux != NULL)
	{
		printf("%d <->", aux->val);
		aux = aux->next;
	}
	printf("NULL\n");
}

void golire(Lista* lista)
{
	Nod* aux = lista->prim;

	while(aux != NULL)
	{
		Nod* current = aux;
		aux = aux->next;
		free(current);
	}

	lista->prim = NULL;
	lista->ultim = NULL;
	lista->size = 0;

	free(lista);
}

void stergere(Lista* lista, int val)
{
	Nod* aux = lista->prim;

	while(aux != NULL)
	{
		if(aux->val == val)
		{
			if(aux->prev == NULL)
				lista->prim = aux->next;
			else
				aux->prev->next = aux->next;
			if(aux->next == NULL)
				lista->ultim = aux->prev;
			else
				aux->next->prev = aux->prev;
			Nod* sters = aux;
			aux = aux->next;
			free(sters);
			lista->size--;
		}
		else
			aux = aux->next;
	}
}

void quicksort(tip_elem a[], int prim, int ultim)
{
	int stanga = prim + 1;
	int dreapta = ultim;

	swap(&a[prim], &a[(prim + ultim)/2]);

	tip_elem pivot = a[prim];

	while(stanga <= dreapta)
	{
		while(stanga <= ultim && a[stanga].cheie < pivot.cheie)
			stanga++;

		while(dreapta >= prim && a[dreapta].cheie > pivot.cheie)
			dreapta--;

		if(stanga < dreapta)
			swap(&a[stanga++], &a[dreapta--]);
		else
			stanga++;
	}

	swap(&a[dreapta], &a[prim]);

	if(prim < dreapta - 1)
		quicksort(a, prim, dreapta - 1);
	if(dreapta + 1 < ultim)
		quicksort(a, dreapta + 1, ultim);
}


void quicksort2(int a[], int prim, int ultim)
{
	int stanga = prim;
	int dreapta = ultim;

	while(stanga <= dreapta)
	{
		while(stanga <= ultim && a[stanga].cheie < 40)
			stanga++;

		while(dreapta >= prim && a[dreapta].cheie > 40)
			dreapta--;

		if(stanga < dreapta)
			swap(&a[stanga++], &a[dreapta--]);
		else
			stanga++;
	}
}

void partition(int a[], int n, int k)
{
	int min;
	for(int i = 0; i < k; i++)
	{
		min = i;
		for(int j = i + 1; j < n; j++)
			if(a[min].cheie > a[j].cheie)
				min = j;
		swap(&a[min], &a[i]);
	}
}


int main(void)
{
	Lista* lista = (Lista*)malloc(sizeof(Lista));

	lista->prim = NULL;
	lista->ultim = NULL;
	lista->size = 0;

	adauga(lista, 1);
	adauga(lista, 2);
	adauga(lista, 3);

	afiseaza(lista);


	return 0;
}