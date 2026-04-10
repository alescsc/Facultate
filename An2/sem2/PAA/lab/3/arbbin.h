#ifndef ARBBIN_H
#define ARBBIN_H

typedef int TCheie;

typedef struct Nod {
    TCheie cheie;
    struct Nod *stg, *dr;
} TNod;

// operatii
TNod* inserare(TNod* r, TCheie x);
TNod* stergere(TNod* r, TCheie x);

// afisare
void inordine(TNod* r);

// utilitare
void distruge(TNod* r);

#endif