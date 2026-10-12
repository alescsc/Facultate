#define ALF 26

typedef struct Trie
{
	struct Trie *copii[ALF];
	int sfarsit;
} Trie;

Trie* nod_nou()
{
	Trie* n = (Trie*)malloc(sizeof(Trie));
	n->sfarsit = 0;
	for(int i = 0; i < ALF; i++)
		n->copii[i] = NULL;
	return n;
}

void inserare(Trie* rad, char* cuv)
{
	Trie* cur = rad;
	for(int i = 0; i < strlen(cuv); i++)
	{
		int index = cuv[i] - 'a';
		if(cur->copii[index] == NULL)
			cur->copii[index] = nod_nou();
		cur = cur->copii[index];
	}
	cur->sfarsit = 1;
}

int cautare(Trie* rad, char* cuv)
{
	Trie *cur = rad;

	for(int i = 0; i < strlen(cuv); i++)
	{
		int index = cuv[i] - 'a';
		if(cur->copii[index] == NULL)
			return 0;
		cur = cur->copii[index];
	}
	return cur->sfarsit;
}

void sterge(Trie* rad, char* cuv)
{
	Trie* cur = rad;
	for(int i = 0; i < strlen(cuv); i++)
	{
		int index = cuv[i] - 'a';
		if(cur->copii[index] == NULL)
			return;
		cur = cur->copii[index];
	}
	cur->sfarsit = 0;
}

void afisare(Trie* nod, char* buffer, int lung)
{
	if(nod == NULL)
		return;
	if(nod->sfarsit == 1)
	{
		buffer[lung] = '\0';
		printf(" - %s\n", buffer);
	}

	for(int i = 0; i < ALF; i++)
		if(nod->copii[i] != NULL)
		{
			buffer[lung] = i + 'a';
			afisare(nod->copii[i], buffer, lung + 1);
		}
}

void golire(Trie *rad)
{
	if(rad == NULL)
		return;

	for(int i = 0; i < ALF; i++)
		if(rad->copii[i] != NULL)
			golire(rad->copii[i]);
	free(rad);
}