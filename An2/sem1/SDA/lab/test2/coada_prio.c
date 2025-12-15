#include <stdio.h>
#include <stdlib.h>

#define LMAX 100

typedef struct {
	int val;
	int p;
} Elem;

typedef struct {
	Elem elem[LMAX];
	int size;
} CoadaPrio;

void init(CoadaPrio *c)
{
	c->size = 0;
}

void swap(Elem *a, Elem *b)
{
	Elem temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(CoadaPrio *c, int i)
{
	int st = 2*i+1;
	int dr = 2*i+2;
	int maxim = i;

	if(st < c->size && c->elem[st].p > c->elem[maxim].p)
		maxim = st;
	if(dr < c->size && c->elem[dr].p > c->elem[maxim].p)
		maxim = dr;

	if(maxim != i)
	{
		swap(&c->elem[i], &c->elem[maxim]);
		heapify(c, maxim);
	}
}

void adauga(CoadaPrio *c, int val, int p)
{
	c->elem[c->size].val = val;
	c->elem[c->size].p = p;
	
	int i = c->size;
	c->size++;

	int parinte = (i-1)/2;

	while(i != 0 && c->elem[parinte].p < c->elem[i].p)
	{
		swap(&c->elem[i], &c->elem[parinte]);
		i = parinte;
		parinte = (i-1)/2;
	}
}

Elem scoate(CoadaPrio *c)
{
	Elem max_elem = c->elem[0];

	c->elem[0] = c->elem[c->size - 1];
	c->size--;

	heapify(c, 0);

	return max_elem;
}

int main(void)
{
	CoadaPrio c;
	init(&c);

	return 0;
}