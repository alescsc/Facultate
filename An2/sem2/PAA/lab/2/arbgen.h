// ARBGEN.HPP - declaratiile claselor Nod si Arbore_generalizat

#include <stdlib.h>
#include <string.h>

typedef struct  Nod
{
	char Nume[30];
	struct Nod *Prim_fiu;
	struct Nod *Frate_drept;
	struct Nod *Tata;

}Arbore_generalizat;

typedef struct Nod* PNod;


PNod Pointer(PNod root, const char * cheie_nod);  // returneaza pointerul spre nodul cu cheia data
void Print(PNod p);  // tipareste un subarbore cu radacina data

// operatori
void Creaza_radacina(PNod *root, const char *nume);  // creaza nodul radacina
void Adauga_fiu(PNod root, const char *nume_tata, const char *nume);
//void Print(PNod root, const char * cheie_nod);  // tipareste subarborele cu rad data prin cheie
PNod Initializare_arbore(PNod root);

// urmatorii operatori returneaza cheile nodurilor din aceeasi "familie" cu nodul cu cheia data   */
char * Tata(PNod root, const char *nume);
char * Prim_fiu(PNod root, const char *nume);
char * Frate_drept(PNod root, const char *nume);

// --- Parcurgeri ---
void preordine(PNod p);   // Radacina -> Stanga -> Dreapta
void inordine(PNod p);    // Stanga -> Radacina -> Dreapta (Primul fiu, apoi Tata, apoi restul fratilor)
void postordine(PNod p);  // Stanga -> Dreapta -> Radacina

// --- Statistici Arbore ---
int inaltime_arbore(PNod p);  // Returneaza inaltimea (adancimea maxima)
int grad_arbore(PNod p);      // Returneaza numarul maxim de copii al oricarui nod
