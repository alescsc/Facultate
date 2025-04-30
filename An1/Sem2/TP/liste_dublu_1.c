#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char sir[255], aux[255];
int f[30];

typedef struct Cuvant{
	char text[16];
	struct Cuvant *pred;
	struct Cuvant *urm;
} Cuvant;

Cuvant *Cuvant_nou(const char *text)
{
	Cuvant *c = (Cuvant*)malloc(sizeof(Cuvant));
	if(!c)
	{
		printf("Memorie insuficienta!");
		exit(EXIT_FAILURE);
	}
	strcpy(c->text,text);
	return c;
}

typedef struct {
	Cuvant *prim;
	Cuvant *ultim;
} Propozitie;

void Propozitie_init(Propozitie *p)
{
	p->prim = p->ultim = NULL;
}

void Propozitie_adauga(Propozitie *p, Cuvant *c)
{
	c->pred = p->ultim;
	if(p->ultim)
	{
		p->ultim->urm = c;
	}
	else
	{
		p->prim = c;
	}
	p->ultim = c;
	c->urm = NULL;
}

Cuvant *Propozitie_cauta(Propozitie *p, const char *text)
{
	Cuvant *c;
	for(c = p->prim; c; c=c->urm)
	{
		if(!strcmp(c->text, text))
			return c;
	}
	return NULL;
}

void Propozitie_sterge(Propozitie *p,Cuvant *c)
{
 	if(c->pred) { 
 		c->pred->urm=c->urm; 
 	}
 	else { 
 		p->prim=c->urm;
 	}
 	if(c->urm) { 
 		c->urm->pred=c->pred; 
 	} 
 	else { 
 		p->ultim=c->pred; 
 	}
 	free(c);
}

void Propozitie_elibereaza(Propozitie *p)
{
	Cuvant *c, *urm;
	for(c = p->prim; c; c=urm)
	{
		urm = c->urm;
		free(c);
	}
	Propozitie_init(p);
}

int main(void)
{
	Propozitie p;
	int op;
	char text[16];
	Cuvant *c;
	Propozitie_init(&p);
	do {
		printf("1 - propozitie noua\n");
 		printf("2 - afisare\n");
		printf("3 - stergere cuvant\n");
 		printf("4 - iesire\n");
 		printf("optiune: ");scanf("%d",&op);
 		switch(op)
 		{
 		case 1:
 			Propozitie_elibereaza(&p);
 			int cnt = 0;
 			for(;;) {
 	 			scanf("%s",text);
 				if(!strcmp(text,"."))
 					break; 
 				for(int i = 0; i < cnt; i++)
 				{
 					char *p = NULL;
 					strcpy(aux,sir);
 					p = strtok(aux, " ");
 					int y = 0, ok = 1;
 					while(p)
 					{
 						y++;
 						if(strcmp(text,p) == 0)
 						{
 							f[y]++;
 							ok = 0;
 						}
 					}
 					if(ok){
 						strcat(sir, " ");
 						strcat(sir, text);
 						sir[strlen(sir) - 1] = '\0';
 						f[y+1] = 1;
 					}
 				}
 				Cuvant *c=Cuvant_nou(text);
 				Propozitie_adauga(&p,c);
 			}
 			break;
 		case 2:
 			for(c=p.prim;c;c=c->urm)printf("%s ",c->text);
 				printf(".\n");
			break;
 		case 3:
 			printf("cuvant de sters:");scanf("%s",text);
 			c=Propozitie_cauta(&p,text);
 			if(c){
 				Propozitie_sterge(&p,c);
 			}
 			else{
 				printf("cuvantul \"%s\" nu se gaseste in propozitie\n",text);
 			}
 		break;
 		case 4: break;
 		default: printf("optiune invalida");
 		}
 	} while(op!=4);
 	return 0;
}