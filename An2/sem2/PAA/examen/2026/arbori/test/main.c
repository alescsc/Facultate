#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nod {
    struct Nod *st, *dr;
    int cheie;
} Nod;

Nod* creare_nod(int x) {
    Nod* n = (Nod*)malloc(sizeof(Nod));
    n->cheie = x;
    n->st = NULL;
    n->dr = NULL;
    return n;
}

Nod* inserare(Nod* n, int x) {
    if (n == NULL)
        return creare_nod(x);
    if (x < n->cheie)
        n->st = inserare(n->st, x);
    else
        if (x > n->cheie)
            n->dr = inserare(n->dr, x);
    return n;
}

Nod* cauta(Nod* n, int x) {
    if (n == NULL || x == n->cheie)
        return n;
    else
        if (x < n->cheie)
            return cauta(n->st, x);
    else
        if (x > n->cheie)
            return cauta(n->dr, x);
}

Nod* min_arbore(Nod* n) {
    while (n->st != NULL)
        n = n->st;
    return n;
}

Nod* stergere(Nod* n, int x) {
    if (n == NULL)
        return NULL;
    else if (x < n->cheie)
        n->st = stergere(n->st, x);
    else
        if (x > n->cheie)
            n->dr = stergere(n->dr, x);
    else {
        if (n->st == NULL) {
            Nod* aux = n->dr;
            free(n);
            return aux;
        }
        else
            if (n->dr == NULL) {
                Nod* aux = n->st;
                free(n);
                return aux;
            }
        Nod* s = min_arbore(n->dr);
        n->cheie = s->cheie;
        n->dr = stergere(n->dr, s->cheie);
    }
    return n;
}

void inordine(Nod* n) {
    if (n == NULL)
        return;
    inordine(n->st);
    printf("%d ", n->cheie);
    inordine(n->dr);
}

void golire(Nod* n) {
    if (n == NULL)
        return;
    golire(n->st);
    golire(n->dr);
    free(n);
}

#define ALF 26

typedef struct Trie {
    struct Trie* copii[ALF];
    int final;
} Trie;

Trie* creare_trie() {
    Trie* t = (Trie*)malloc(sizeof(Trie));
    t->final = 0;
    for (int i = 0; i < ALF; i++)
        t->copii[i] = NULL;
    return t;
}

void inserare_trie(Trie* rad, char* cuv) {
    Trie* n = rad;
    for (int i = 0; i < strlen(cuv); i++) {
        int index = cuv[i] - 'a';
        if (n->copii[index] == NULL)
            n->copii[index] = creare_trie();
        n = n->copii[index];
    }
    n->final = 1;
}

int cauta_trie(Trie* rad, char* cuv) {
    Trie* n = rad;
    for (int i = 0; i < strlen(cuv); i++) {
        int index = cuv[i] - 'a';
        if (n->copii[index] == NULL)
            return 0;
        n = n->copii[index];
    }
    return n->final;
}

void sterge_trie(Trie* rad, char* cuv) {
    Trie* n = rad;
    for (int i = 0; i < strlen(cuv); i++) {
        int index = cuv[i] - 'a';
        if (n->copii[index] == NULL)
            return;
        n = n->copii[index];
    }
    n->final = 0;
}

void afisare(Trie* rad, char *buffer, int lung) {
    if (rad == NULL)
        return;
    if (rad->final == 1) {
        buffer[lung] = '\0';
        printf("%s\n", buffer);
    }
    for (int i = 0; i < ALF; i++) {
        if (rad->copii[i] != NULL) {
            buffer[lung] = i + 'a';
            afisare(rad->copii[i], buffer, lung + 1);
        }
    }
}

void golire_trie(Trie* rad) {
    if (rad == NULL)
        return;
    for (int i = 0; i < ALF; i++)
        if (rad->copii[i] != NULL)
            golire_trie(rad->copii[i]);
    free(rad);
}

int main(void) {
    Nod* rad = NULL;
    rad = inserare(rad, 10);
    rad = inserare(rad, 823);
    rad = inserare(rad, 23);
    rad = inserare(rad, 1);
    rad = inserare(rad, 83);
    rad = inserare(rad, 123);
    rad = inserare(rad, 78);
    rad = inserare(rad, 3);
    inordine(rad);
    printf("\n");
    rad = stergere(rad, 23);
    rad = stergere(rad, 823);
    inordine(rad);
    printf("\n");
    if (cauta(rad, 3))
        printf("Este!");
    golire(rad);

    Trie* rad2 = creare_trie();
    inserare_trie(rad2, "car");
    inserare_trie(rad2, "cat");
    inserare_trie(rad2, "tiger");
    inserare_trie(rad2, "tigers");
    char buffer[100] = {0};
    afisare(rad2, buffer, 0);
    sterge_trie(rad2, "tiger");
    afisare(rad2, buffer, 0);

    golire_trie(rad2);
    return 0;
}