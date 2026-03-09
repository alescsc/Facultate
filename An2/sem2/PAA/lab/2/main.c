// ARBGENM.CPP - program de test

#include "arbgen.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void main()
{


	Arbore_generalizat *arbore=NULL;

	Creaza_radacina(&arbore,"radacina");
	Adauga_fiu(arbore,"radacina", "fiu1");
	Adauga_fiu(arbore,"radacina", "fiu2");
	Adauga_fiu(arbore, "fiu1", "fiu11");
	Adauga_fiu(arbore, "radacina", "fiu3");
	Adauga_fiu(arbore, "fiu2", "fiu21");
	Adauga_fiu(arbore, "fiu1", "fiu12");
	Adauga_fiu(arbore, "fiu3", "fiu31");
	Adauga_fiu(arbore, "radacina", "fiu4");
	Adauga_fiu(arbore, "fiu1", "fiu13");
	Adauga_fiu(arbore, "fiu1", "fiu14");
	Adauga_fiu(arbore, "fiu2", "fiu22");
	Adauga_fiu(arbore, "fiu1", "fiu15");
	Adauga_fiu(arbore, "fiu3", "fiu32");

	Print(arbore);
	preordine(arbore);

	printf("tatal lui fiu15 e %s\n", Tata(arbore, "fiu15"));
	printf("primul fiu al lui fiu2 e %s\n", Prim_fiu(arbore, "fiu2"));
	printf("fratele drept al lui fiu13 e %s\n", Frate_drept(arbore, "fiu13"));


	arbore=Initializare_arbore(arbore);

	Creaza_radacina(&arbore, "rad");
	Adauga_fiu(arbore, "rad", "f1");
	Adauga_fiu(arbore, "rad", "f2");
	Adauga_fiu(arbore, "f1", "f11");
	Adauga_fiu(arbore, "rad", "f3");

	Print(arbore);
	preordine(arbore);
	printf("\n");
	postordine(arbore);
	printf("\n");
	inordine(arbore);
}
