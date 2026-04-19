// ARBGEN.CPP - implementarea clasei Arbore_generalizat

#include "arbgen.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void Creaza_radacina(PNod *Root,const char *nume)
// creaza nodul radacina
{
	if (*Root)
		printf("exista deja o radacina\n");
	else
	{
		*Root = (PNod)malloc(sizeof(struct Nod));
		strcpy((*Root)->Nume, nume);
		(*Root)->Frate_drept = NULL;
		(*Root)->Prim_fiu = NULL;
		(*Root)->Tata = NULL;
	}
}

char tipar[40] = "";  // folosesc la tiparirea arborelui


char * Tata(PNod root, const char *nume)
{
	PNod p;
	p=Pointer(root, nume);
	return p->Tata->Nume;
}
char * Prim_fiu(PNod root, const char *nume)
{
	PNod p;
	p = Pointer(root, nume);
	return p->Prim_fiu->Nume;
}
char * Frate_drept(PNod root, const char *nume)
{
	PNod p;
	p = Pointer(root, nume);
	return p->Frate_drept->Nume;
}


void Print(PNod p)  // tiparire in preordine
{
	printf("%s %s\n", tipar, p->Nume);
	for (PNod r = p->Prim_fiu; r; r = r->Frate_drept)
	{
		//printf("%s %s %s\n",tip1, tipar, r->Nume);
		strcat(tipar, "\t");
		Print(r);
		if (strlen(tipar)>=strlen("\t"))
			tipar[strlen(tipar) - strlen("\t")] = '\0';
	}

}



PNod Pointer(PNod root, const char * cheie_nod)
{
	PNod r1,p;
	p = root;
	if (p){
		if (!strcmp(p->Nume, cheie_nod))
			return p;
		for (PNod r = p->Prim_fiu; r; r = r->Frate_drept)
		{
			if (!strcmp(r->Nume, cheie_nod))
				return r;

			r1= Pointer(r,cheie_nod);
			if (r1) return r1;
		}
		return NULL;
	}
	return NULL;
}



void Adauga_fiu(PNod Root, const char *nume_tata, const char *nume)
{
	PNod s = NULL;
	PNod r;
	PNod p = Pointer(Root, nume_tata);
	if (p){
		s = (PNod)malloc(sizeof(struct Nod));
		strcpy(s->Nume, nume);// se creaza un nou nod
		s->Frate_drept = NULL;
		s->Prim_fiu = NULL;
		s->Tata = p;
		if (!(p->Prim_fiu))  // primul fiu
			p->Prim_fiu = s;
		else {
			for ( r = p->Prim_fiu; r->Frate_drept; r = r->Frate_drept);
			r->Frate_drept = s;  // mai exista fii, noul fiu devine ultimul
		}
	}

}



PNod Initializare_arbore(PNod Root)
{
	PNod r=NULL,p;
	if (Root)
			p = Root;
	if (p){
		for ( r = p->Prim_fiu; r; r = r->Frate_drept)
			return Initializare_arbore(r);
		free (p);
	}
	return NULL;
}

// IMPLEMENTARE FUNCTII LAB
// parcurgere preordine RADACINA, STANGA, DREAPTA
void preordine(PNod p)
{
	if(!p) return;
	printf("%s ", p->Nume);
    for(PNod r = p->Prim_fiu; r; r = r->Frate_drept)
			preordine(r);
}

// parcurgere inordine STANGA, RADACINA, DREAPTA
void inordine(PNod p)
{
	if(!p) return;
	if(p->Prim_fiu)
          inordine(p->Prim_fiu); // merg maxim in stanga
	printf("%s ", p->Nume); // dupa ce am mers maxim in stanga afisez radacina
	if(p->Prim_fiu)
          for(PNod r = p->Prim_fiu->Frate_drept; r; r = r->Frate_drept) // ma ocup de dreapta
            	inordine(r);
}

// parcurgere postordine STANGA, DREAPTA, RADACINA
void postordine(PNod p)
{
	if(!p) return;
    for(PNod r = p->Prim_fiu; r; r = r->Frate_drept)
			postordine(r);
	printf("%s ", p->Nume);
}

// inaltime arbore
int inaltime_arbore(PNod p)
{
	if(!p) return 0;
	int max_h = 0;
	for(PNod r = p->Prim_fiu; r; r = r->Frate_drept)
	{
		int h = inaltime_arbore(r);
		if(h > max_h)
			max_h = h;
	}
	return max_h + 1;
}

// grad maxim
int grad_arbore(PNod p)
{
	if(!p) return 0;
    int nr_fii = 0;
    for(PNod r = p->Prim_fiu; r; r = r->Frate_drept)
		nr_fii++;
    int grad_max = nr_fii;
    for(PNod r = p->Prim_fiu; r; r = r->Frate_drept)
	{
		int g = grad_arbore(r);
		if(g > grad_max)
			grad_max = g;
	}
	return grad_max;
}

// afisare frunze
void afisare_frunze(PNod p)
{
	if(!p) return;
	if(p->Prim_fiu != NULL)
          printf("%s ", p->Nume);
    for(PNod r = p->Prim_fiu; r; r = r->Frate_drept)
			afisare_frunze(r);
}

// numarare frunze
int numarare_frunze(PNod p)
{
	if(!p) return 0;
    if(p->Prim_fiu != NULL)
           return 1;
	int nr = 0;
	for(PNod r = p->Prim_fiu; r; r = r->Frate_drept)
		nr = nr + numarare_frunze(r);
	return nr;
}

// eliberare
void distruge_arbore(PNod p)
{
    // 1. Conditia de oprire a recursivitatii
    if (p == NULL) return;

    // 2. Coboram maxim in adancime (eliberam toti fiii primului fiu)
    distruge_arbore(p->Prim_fiu);

    // 3. Mergem pe orizontala (eliberam toti fratii din dreapta)
    distruge_arbore(p->Frate_drept);

    // 4. Abia acum, cand "sub" si la "dreapta" nodului curent nu mai este nimic,
    // il putem sterge pe el insusi in siguranta.
    free(p);
}