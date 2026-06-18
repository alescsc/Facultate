#define ALF 26

typedef struct Trie
{
	struct Trie* copii[ALF];
	int final;
} Trie;

Trie* nod_nou()
{
	Trie* n = (Trie*)malloc(sizeof(Trie));
	n->final = 0;
	for(int i = 0; i < ALF; i++)
		n->copii[i] = NULL;
	return n;
}

void inserare(Trie* rad, char* cuv)
{
	Trie* n = rad;

	for(int i = 0; i < strlen(cuv); i++)
	{
		int index = cuv[i] - 'a';
		if(n->copii[index] == NULL)
			n->copii[index] = nod_nou();
		n = n->copii[index];
	}
	n->final = 1;
}

int cauta(Trie* rad, char* cuv)
{
	Trie* n = rad;

	for(int i = 0; i < strlen(cuv); i++)
	{
		int index = cuv[i] - 'a';
		if(n->copii[index] == NULL)
			return 0;
		n = n->copii[index];
	}
	return n->final;
}

void sterge(Trie* rad, char* cuv)
{
	Trie* n = rad;

	for(int i = 0; i < strlen(cuv); i++)
	{
		int index = cuv[i] - 'a';
		if(n->copii[index] == NULL)
			return;
		n = n->copii[index];
	}
	n->final = 0;
}

void afisare(Trie* nod, char* buffer, int lung)
{
	if(nod == NULL)
		return;
	if(nod->final == 1)
	{
		buffer[lung] = '\0';
		printf("%s\n", buffer);
	}

	for(int i = 0; i < ALF; i++)
		if(nod->copii[i] != NULL)
		{
			buffer[lung] = i + 'a';
			afisare(nod->copii[i], buffer, lung + 1);
		}
}

void golire(Trie* rad)
{
	if(rad == NULL)
		return;

	for(int i = 0; i < ALF; i++)
		if(rad->copii[i] != NULL)
			golire(rad->copii[i]);
	free(rad);
}