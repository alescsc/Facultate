#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LMAX 100

typedef struct 
{
	char id[10];
	int p;	
}Elem;

typedef struct
{
	int size;
	Elem elem[LMAX];
}Coada;

typedef struct
{
	Elem elem[LMAX];
	int varf_stiva;
}stiva;

stiva st;

void init_st()
{
	st.varf_stiva = 0;
}

void push(Elem e)
{
	st.elem[st.varf_stiva] = e;
	st.varf_stiva++;
}

Elem anuleaza_ultimul()
{
	st.varf_stiva--;
	return st.elem[st.varf_stiva];
}

void init(Coada *c)
{
	c->size = 0;
}

void swap(Elem *a, Elem *b)
{
	Elem temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(Coada *c, int i)
{
	int st = 2*i+1;
	int dr = 2*i+2;
	int maxim = i;

	if(st < c->size && c->elem[st].p < c->elem[maxim].p)
		maxim = st;

	if(dr < c->size && c->elem[dr].p < c->elem[maxim].p)
		maxim = dr;

	if(maxim != i)
	{
		swap(&c->elem[i], &c->elem[maxim]);
		heapify(c, maxim);
	}
}

void adauga_task(Coada *c, char id[], int p)
{
	c->elem[c->size].p = p;
	strcpy(c->elem[c->size].id, id);

	int i = c->size;
	c->size++;

	int parinte = (i-1)/2;

	while(i != 0 && c->elem[parinte].p > c->elem[i].p)
	{
		swap(&c->elem[parinte], &c->elem[i]);
		i = parinte;
		parinte = (i-1)/2;
	}
}

Elem executa(Coada *c)
{
	Elem elem_maxim = c->elem[0];
	c->elem[0] = c->elem[c->size - 1];
	c->size--;
	push(elem_maxim);

	heapify(c, 0);

	return elem_maxim;
}

void listare(Coada *c)
{
	printf("Afisare coada cu prioritate: ");
	for(int i = 0; i < c->size; i++)
		printf("[%s P%d] ", c->elem[i].id, c->elem[i].p);

	printf("\nAfisare stiva: ");
	for(int i = st.varf_stiva - 1; i >= 0; i--)
		printf("[%s P%d] ", st.elem[i].id, st.elem[i].p);
}

int main(void)
{
	Coada c;
	init(&c);
	init_st();
	FILE *f = NULL;
	if((f = fopen("Fabrica.txt", "r")) == NULL)
	{
		perror("Fisierul nu s-a putut deschide!");
		exit(-1);
	}
	int n;
	fscanf(f, "%d", &n);
	char car = fgetc(f);
	char s[100];
	Elem aux;
	while(n)
	{
		fgets(s, 100, f);
		if(n == 1)
			s[strlen(s) - 1] = '\0';
		char *p = strtok(s, " ");
		int i = 0;
		while(p)
		{
			if(i == 0)
				strcpy(aux.id, p);
			else
				aux.p = atoi(p);
			i++;
			p = strtok(NULL, " ");
		}
		adauga_task(&c, aux.id, aux.p);
		n--;
	}
	listare(&c);
	printf("\n");
	executa(&c);
	executa(&c);
	listare(&c);
	if(fclose(f) != 0)
	{
		perror("Eroare la inchiderea fisierului!");
		exit(-1);
	}
	return 0;
}