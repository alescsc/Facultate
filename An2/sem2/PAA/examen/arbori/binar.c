typedef struct Nod 
{
	int cheie;
	struct Nod *stanga, *dreapta;
} Nod;

Nod* nod_nou(int x)
{
	Nod *n = (Nod*)malloc(sizeof(Nod));
	n->cheie = x;
	n->stanga = n->dreapta = NULL;
	return n;
}

Nod* inserare(Nod *n, int x)
{
	if(n == NULL)
		return nod_nou(x);
	if(x < n->cheie)
		n->stanga = inserare(n->stanga, x);
	else
		if(x > n->cheie)
			n->dreapta = inserare(n->dreapta, x);
	return n;
}

Nod* cautare(Nod *n, int x)
{
	if(n == NULL || n->cheie == x)
		return n;

	if(x < n->cheie)
		return cautare(n->stanga, x);
	else
		return cautare(n->dreapta, x);
}

Nod *min_subarbore(Nod *n)
{
	while(n->stanga != NULL)
		n = n->stanga;
	return n;
}

Nod* stergere(Nod *n, int x)
{
	if(n == NULL)
		return NULL;
	if(x < n->cheie)
		n->stanga = stergere(n->stanga, x);
	else
		if(x > n->cheie)
			n->dreapta = stergere(n->dreapta, x);
		else
		{
			if(n->stanga == NULL)
			{
				Nod* aux = n->dreapta;
				free(n);
				return aux;
			}
			else
				if(n->dreapta == NULL)
				{
					Nod* aux = n->stanga;
					free(n);
					return aux;
				}

			Nod* s = min_subarbore(n->dreapta);
			n->cheie = s->cheie;
			n->dreapta = stergere(n->dreapta, s->cheie);
		}
	return n;
}

void inordine(Nod *n)
{
	if(n == NULL)
		return;

	inordine(n->stanga);
	printf("%d ", n->cheie);
	inordine(n->dreapta);
}

void golire(Nod *n)
{
	if(n == NULL)
		return;
	golire(n->stanga);
	golire(n->dreapta);
	free(n);
}

int inaltime(Nod* n) {
    if (n == NULL) 
        return 0;
  
    int inaltime_stanga = inaltime_bst(n->st);
    int inaltime_dreapta = inaltime_bst(n->dr);

    if (inaltime_stanga > inaltime_dreapta) 
        return inaltime_stanga + 1;
    else
        return inaltime_dreapta + 1;
}

in main declar:
Nod* radacina = NULL;

radacina = inserare(radacina, VALOARE);