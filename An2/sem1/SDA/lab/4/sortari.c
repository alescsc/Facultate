#include <stdio.h>
#include <stdlib.h>

typedef struct {
	double marime;
} structura;

void swap(structura *a, structura *b)
{
	structura temp = *a;
	*a = *b;
	*b = temp;
}

void bubblesort(structura* p, int size)
{
	for(int i = 0; i < size-1; i++)
		for(int j = i + 1; j < size; j++)
			if(p[i].marime > p[j].marime)
				swap(&p[i], &p[j]);
}

void insertion_sort(structura* p, int size)
{
	strucutra temp;
	for(int i = 1; i < n; i++)
	{
		temp = p[i];
		for(int j = i; (j>0) && (temp.marime < p[j-1].marime); j--)
			p[j] = p[j - 1];
		p[j] = temp;
	}
}

void selection_sort(structura* p, int size)
{
	int mini;
	for(int i = 0; i < size - 1; i++)
	{
		mini = i;
		for(int j = i + 1; j < size; j++)
		{
			if(p[j].marime < p[mini].marime)
				mini = j;
		}
		swap(&p[mini],&p[i]);
	}
}

void afisare(structura* p, int size)
{
	for(int i = 0; i < size; i++)
		printf("%lf\n", p[i].marime);
}

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		perror("Nu sunt suficiente argumente!");
		exit(-1);
	}

	FILE *f = NULL;
	if((f = fopen(argv[1], "r")) == NULL)
	{
		perror("Nu s-a putut deschide fisierul!");
		exit(-1);
	}

	structura aux, *p = NULL;
	p = (structura *)malloc(sizeof(structura));
	int index = 0;

	while(fscanf(f, "%lf", &aux.marime) != EOF)
	{
		structura *temp = NULL;
		temp = (structura *)realloc(p, (index+1)*sizeof(structura));
		if(temp == NULL)
		{
			perror("Eroare la alocare dinamica!");
			fclose(f);
			free(p);
			exit(-1);
		}
		p = temp;
		p[index] = aux;
		index++;
	}
	printf("Vector intial:\n");
	afisare(p, index);
	bubblesort(p, index);
	printf("\nVector sortat:\n");
	afisare(p, index);
	free(p);
	if(fclose(f) != 0)
	{
		perror("Eroare la incihderea fisierului!");
		exit(-1);
	}
	return 0;
}