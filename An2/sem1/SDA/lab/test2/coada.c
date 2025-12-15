#include <stdio.h>
#include <stdlib.h>

#define NMAX 30

typedef struct coada
{
	char elemente[NMAX];
	int citire;
	int scriere;
} coada;

coada init(coada c)
{
	c.citire = 0;
	c.scriere = NMAX - 1;
	return c;
}

int vid(coada c)
{
	if(c.citire == (c.scriere + 1) % NMAX)
		return 1;
	return 0;
}

int plina(coada c)
{
	if(c.citire == (c.scriere + 2) % NMAX)
		return 1;
	else
		return 0;
}

coada adauga(coada c, char car)
{
	if(!plina(c))
	{
		c.scriere = (c.scriere + 1) % NMAX;
		c.elemente[c.scriere] = car;
	}
	return c;
}

char scoate(coada *c)
{
	char element = '\0';
	if(!vid(*c))
	{
		element = c->elemente[c->citire];
		c->citire = ((c->citire) + 1) % NMAX;
	}
	return element;
}

void afisare(coada c) {
    int i;
    int numar_elemente;

    if (vid(c)) {
        printf("Starea curenta: Coada este vida.\n");
        return;
    }

    // Calculam numarul de elemente: (scriere - citire + NMAX) % NMAX + 1
    numar_elemente = (c.scriere - c.citire + NMAX) % NMAX + 1;

    printf("\n[ Coada (Elemente: %d) ]\n", numar_elemente);
    printf("   HEAD -> [ ");
    
    for (i = 0; i < numar_elemente; i++) {
        int index_curent = (c.citire + i) % NMAX;
        
        printf("%c", c.elemente[index_curent]);
        
        if (i < numar_elemente - 1) {
            printf(", ");
        }
    }

    printf(" ] <- TAIL\n");
    printf("   Pointeri: (Citire: %d, Scrierea: %d)\n", c.citire, c.scriere);
}

int main(void)
{
	coada q = init(q);

	q = adauga(q, 'A');
	q = adauga(q, 'B');
	q = adauga(q, 'C');
	afisare(q);
	return 0;
}