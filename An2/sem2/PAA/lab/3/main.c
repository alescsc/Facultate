#include <stdio.h>
#include "arbbin.h"

int main()
{
    TNod* rad = NULL;

    // inserari
    rad = inserare(rad, 50);
    rad = inserare(rad, 30);
    rad = inserare(rad, 70);
    rad = inserare(rad, 20);
    rad = inserare(rad, 40);
    rad = inserare(rad, 60);
    rad = inserare(rad, 80);

    printf("Arbore (inordine): ");
    inordine(rad);

    // stergere
    printf("\nStergem 30...\n");
    rad = stergere(rad, 30);

    printf("Arbore dupa stergere: ");
    inordine(rad);

    // eliberare memorie
    distruge(rad);

    return 0;
}