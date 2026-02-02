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
	nou->prev = NULL;
	nou->next = NULL;
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
		printf("%d <-> ", aux->val);
		aux = aux->next;
	}
	printf("NULL");
}

void sterge(Lista* lista, int val)
{
	Nod* aux = lista->prim;

	while(aux != NULL)
	{
		if(aux->val == val)
		{
			if(aux->prev != NULL)  // daca nu e primu
				aux->prev->next = aux->next;
			else
				lista->prim = aux->next; // daca e primu

			if(aux->next != NULL) // daca nu e ultim
				aux->next->prev = aux->prev; 
			else
				lista->ultim = aux->prev; // daca e ultim

			Nod* sters = aux;
			aux = aux->next;
			free(sters);
			lista->size--;
		}
		else
			aux = aux->next;
	}
}

void eliberare(Lista* lista)
{
	if(lista == NULL)
		return;

	Nod* aux = lista->prim;
	while(aux != NULL)
	{
		Nod* aux1 = aux->next;
		free(aux);
		aux = aux1;
	}

	free(lista);
}

int main(void)
{
	Lista* lista = (Lista*)malloc(sizeof(Lista));
	lista->prim = NULL;
	lista->ultim = NULL;
	lista->size = 0;

	adauga(lista, 7);
	adauga(lista, 12);
	adauga(lista, 2024);

	afiseaza(lista);
	printf("\n");

	sterge(lista, 2024);
	sterge(lista, 7);

	afiseaza(lista);

	eliberare(lista);
	return 0;
}