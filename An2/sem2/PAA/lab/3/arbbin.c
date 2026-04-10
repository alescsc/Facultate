#include <stdio.h>
#include <stdlib.h>
#include "arbbin.h"

// inserare
TNod* inserare(TNod* r, TCheie x)
{
    if (!r)
    {
        TNod* nou = (TNod*)malloc(sizeof(TNod));
        nou->cheie = x;
        nou->stg = nou->dr = NULL;
        return nou;
    }

    if (x < r->cheie)
        r->stg = inserare(r->stg, x);
    else if (x > r->cheie)
        r->dr = inserare(r->dr, x);

    return r;
}

// minim (folosit la stergere)
static TNod* minim(TNod* r)
{
    while (r && r->stg)
        r = r->stg;
    return r;
}

// stergere
TNod* stergere(TNod* r, TCheie x)
{
    if (!r)
        return NULL;

    if (x < r->cheie)
        r->stg = stergere(r->stg, x);
    else if (x > r->cheie)
        r->dr = stergere(r->dr, x);
    else
    {
        // fara fii
        if (!r->stg && !r->dr)
        {
            free(r);
            return NULL;
        }
        // un fiu dreapta
        else if (!r->stg)
        {
            TNod* temp = r->dr;
            free(r);
            return temp;
        }
        // un fiu stanga
        else if (!r->dr)
        {
            TNod* temp = r->stg;
            free(r);
            return temp;
        }

        // doi fii
        TNod* temp = minim(r->dr);
        r->cheie = temp->cheie;
        r->dr = stergere(r->dr, temp->cheie);
    }

    return r;
}

// afisare inordine
void inordine(TNod* r)
{
    if (!r)
        return;

    inordine(r->stg);
    printf("%d ", r->cheie);
    inordine(r->dr);
}

// eliberare memorie
void distruge(TNod* r)
{
    if (!r)
        return;

    distruge(r->stg);
    distruge(r->dr);
    free(r);
}

// IMPLEMENTARE LAB
// parcurgere preordine
void preordine(Tnod* r)
{
    if(!r) return;
    printf("%d ", r->cheie);
    preordine(r->stg);
    preordine(r->dr);
}

// parcurgere inordine
void inordine(TNod* r)
{
    if(!r) return;
    inordine(r->stg);
    printf("%d ", r->cheie);
    inordine(r->dr);
}

// parcurgere postordine
void postordine(TNod* r)
{
    if(!r) return;
    postordine(r->stg);
    postordine(r->dr);
    printf("%d ", r->cheie);
}

// inaltime
int inaltime(TNod* r)
{
    if(!r) return 0;
    int h_stg = inaltime(r->stg);
    int h_dr = inaltime(r->dr);
    if(h_stg < h_dr)
        return h_dr + 1;
    else
        return h_stg + 1;
}

// grad maxim
int grad_maxim(TNod* r)
{
    if(!r) return 0;

    int grad_curent 0;
    if(r->stg != NULL)
        grad_curent++;
    if(r->dr != NULL)
        grad_curent++;
    if(grad_curent == 2)
        return 2;

    int grad_max = 0;
    int grad_st = grad_maxim(r->stg);
    int grad_dr = grad_maxim(r->dr);
    if(grad_st > grad_dr)
        grad_max = grad_st;
    else grad_max = grad_dr;

    if(grad_max > grad_curent)
        return grad_max;
    else
        return grad_curent;
}