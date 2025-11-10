//
// Created by alex_ on 11/10/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nume[100];
    float Distanta_LY, Luminoziate;
    float Indice;
} Galactic;

/*
 *Am ales sa sortez cu MergeSort deoarece avem un set masiv de date
 *Aceasta sortare se bazeaza pe principiul Divide et Impera
 *MergeSort are eficienta O(n * logn)
 *Sortarea aceasta este stabila (nu schmba ordinea elementelor egale) insa nu este in-situ (se face in vectori auxiliari)
 */


void merge(Galactic *a, int l, int m, int r) {
    int a1_count = m - l + 1;
    int a2_count = r - m;
    Galactic *a1 = (Galactic*)malloc(a1_count * sizeof(Galactic));
    Galactic *a2 = (Galactic*)malloc(a2_count * sizeof(Galactic));
    int i, j, k;
    for (i = 0; i < a1_count; i++)
        a1[i] = a[l + i];
    for (j = 0; j < a2_count; j++)
        a2[j] = a[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < a1_count && j < a2_count) {
        if (a1[i].Indice <= a2[j].Indice) {
            a[k++] = a1[i++];
        } else {
            a[k++] = a2[j++];
        }
    }
    // adaugăm în 'a' elementele rămase în 'a1'
    while (i < a1_count) {
        a[k++] = a1[i++];
    }
    // adaugăm în 'a' elementele rămase în 'a2'
    while (j < a2_count) {
        a[k++] = a2[j++];
    }
    free(a1);
    free(a2);
}

void _mergeSort(Galactic *a, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2; // echivalent (l + r) / 2, dar ne ferește de overflow
        _mergeSort(a, l, m);
        _mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

void mergeSort(Galactic *a, int a_count) {
    _mergeSort(a, 0, a_count - 1);
}

void swap(Galactic *a, Galactic *b) {
    Galactic temp = *b;
    *b = *a;
    *a = temp;
}
/*
 * Partial_sort l-am efectuat folosind sortarea prin selectie
 * Aceasta ne permite sa accesam direct doar primele k elemente cele mai mici
 * fara a sorta intregul vector pentru ale gasi, deoarece acesta
 * lucreaza mereu cu elementul minim curent punandu-l pe pozitia potrivia
 *
 * Aceasta sortare este in-situ dar nu e stabila.
 *
 * Are o eficienta O(n) [O(n*k) insa k este o constanta]
 *
 * Este mai rapid decat o sortare completa, acesta neavand sa sorteze
 * intregul vector de elemente.
 *
 * Fata de mergeSortul efectat anterior, acest partial_sort e mai rapid
 *
 */
void partial_sort(Galactic *arr, int n, int k) {
    int i, j, min;
    for (i = 0; i < k; i++) {
        min = i; // punem indicele de minim ca fiind cel al elementului curent
        for (j = i + 1; j < n; j++) {
            if (arr[min].Indice > arr[j].Indice) {
                min = j; // cautam daca exista un nr mai mic decat acesta si schimbam indicele de minim
            }
        }
        swap(&arr[min], &arr[i]); // punem minimul la pozitia sa potrivita
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) { //verificam nr de argumente
        printf("Numar de argumente incorect!");
        exit(-1);
    }

    FILE *f = NULL;
    if ((f = fopen(argv[1], "r")) == NULL) { //verificam daca am deschis bine fisierul
        printf("Eroare la deschiderea fisierului!");
        exit(-1);
    }

    char linie[1024];
    fgets(linie, 1024, f); // citim prima linie care ne specifica formatul fisierului, ignorand-o

    Galactic a[5000];
    int index = 0;
    while (fgets(linie, 1024, f) != NULL) {
        if (index == 5000) {
            printf("Prea multe input-uri pentru array! Peste 5000!"); //avem grija sa nu avem overflow la array
            exit(-1);
        }
        char *p = NULL;
        p = strtok(linie, "\t"); // utilizam strtok pentru a separa datele din linie
        int i = 0;
        while (p != NULL) {
            if (i == 0) {
                a[index].id = atoi(p);
            }
            else if (i == 1) {
                strcpy(a[index].nume, p);
            }
            else if (i == 2) {
                a[index].Distanta_LY = atof(p);
            }
            else if (i == 3) {
                a[index].Luminoziate = atof(p);
            }
            i++;
            p = strtok(NULL, "\t");
        }
        a[index].Indice = a[index].Distanta_LY/a[index].Luminoziate;
        index++;
    }

    for (int i = 0; i < 5000; i++) {
        printf("%d %s %f %f %f\n", a[i].id, a[i].nume, a[i].Distanta_LY, a[i].Luminoziate, a[i].Indice);
    } // facem o afisare initiala pentru a vedea ca totul s a citit bine

    printf("------------------------------------\n");
    mergeSort(a, 5000);
    printf("Primele 10 cele mai vizibile obiecte: \n");
    for (int i = 0; i < 10; i++) {
        printf("%d %s %f %f %f\n", a[i].id, a[i].nume, a[i].Distanta_LY, a[i].Luminoziate, a[i].Indice);
    }

    printf("------------------------------------\n");
    printf("Ultimele 10 cele mai vizibile obiecte: \n");
    for (int i = 4999; i > 4989; i--) {
        printf("%d %s %f %f %f\n", a[i].id, a[i].nume, a[i].Distanta_LY, a[i].Luminoziate, a[i].Indice);
    }

    printf("------------------------------------\n");
    printf("Primele k = 15 elemente sortate fara a sorta intregul vector:\n");
    partial_sort(a, 5000, 15);
    for (int i = 0; i < 16; i++) { // se poate vedea la rulare ca elementul 16 deja nu mai este sortat daca nu am face mergeSort inainte
        printf("%d %s %f %f %f\n", a[i].id, a[i].nume, a[i].Distanta_LY, a[i].Luminoziate, a[i].Indice);
    }


    if (fclose(f) != 0) {
        printf("Eroare la inchiderea fisierului!");
        exit(-1);
    }
    return 0;
}
