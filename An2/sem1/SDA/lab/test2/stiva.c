#include <stdio.h>
#include <stdlib.h>

#define NMAX 100

typedef struct {
	char corp_stiva[NMAX];
	int varf_stiva;
} Stiva;

void init(Stiva *s)
{
	s->varf_stiva = 0;
}

int push(Stiva *s, char car)
{
	s->corp_stiva[s->varf_stiva] = car;
	s->varf_stiva++;
	return 1;
}

char pop(Stiva *s)
{
	s->varf_stiva--;
	return s->corp_stiva[s->varf_stiva];
}

char peek(Stiva *s)
{
	return s->corp_stiva[s->varf_stiva - 1];
}

int cauta(Stiva *s, char car_cautat)
{
	for(int i = s->varf_stiva - 1; i >= 0; i--)
		if(s->corp_stiva[i] == car_cautat)
			return 1;
	return 0;
}

void afiseaza_stiva(Stiva *s)
{
	for(int i = s->varf_stiva - 1; i >= 0; i--)
		printf("%c ", s->corp_stiva[i]);
}

int main(void)
{
	Stiva s;
	init(&s);
	push(&s, 'A');
	push(&s, 'B');
	push(&s, 'C');

	afiseaza_stiva(&s);
	printf("\n");

	pop(&s);

	int i = cauta(&s, 'C');
	printf("%d \n", i);

	afiseaza_stiva(&s);
	return 0;
}