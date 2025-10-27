#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "timer.h"

#define n 1000

typedef struct Angajati {
    int id, varsta;
    char nume[30], departament[30];
    double salariu;
} Angajati;

void swap(Angajati* a, Angajati* b) {
    Angajati temp = *a;
    *a = *b;
    *b = temp;
}

void bubblesort(Angajati* a, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++)
            if (a[i].salariu < a[j].salariu)
                swap(&a[i], &a[j]);
    }
}


#define T 3
int h[T];

void generare_incrementi(int h[], int t) {
    int i;
    h[T - 1] = 1;
    for (i = T - 2; i >= 0; i--) {
        h[i] = 3 * h[i + 1] + 1;
    }
}

void shell_sort(Angajati *a, int size) {
    int i, j, k, hCnt, H;
    Angajati temp;
    generare_incrementi(h, T);
    for (i = 0; i < T; i++) {
        H = h[i];
        for (hCnt = 0; hCnt < H; hCnt++) {
            for (j = H+hCnt; j < size; j = j + H) {
                temp = a[j];
                for (k = j; (k-H>=0) && temp.salariu < a[k-H].salariu; k=k-H)
                    a[k] = a[k-H];
                a[k] = temp;
            }
        }
    }
}



double medie(Angajati* a, int size) {
    double medie = 0;
    for (int i = 0; i < size; i++)
        medie = medie + a[i].salariu;
    medie = medie / size;
    return medie;
}

double mini(Angajati* a, int size) {
    double mini = a[0].salariu;
    for (int i = 1; i < size; i++)
        if (a[i].salariu < mini)
            mini = a[i].salariu;
    return mini;
}

double maxi(Angajati* a, int size) {
    double maxi = a[0].salariu;
    for (int i = 1; i < size; i++)
        if (a[i].salariu > maxi)
            maxi = a[i].salariu;
    return maxi;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Nu au fost introduse destule argumente!");
        exit(-1);
    }

    FILE *f = NULL;
    if ((f = fopen(argv[1], "r")) == NULL) {
        printf("Eroare la deschiderea fisierului!");
        exit(-1);
    }

    Angajati aux, *a = NULL;
    a = (Angajati *)malloc(sizeof(Angajati));
    int index = 0;
    for (int i = 0; i < n; i++){
        Angajati *temp = NULL;
        temp = realloc(a, (index + 1) * sizeof(Angajati));
        if (temp == NULL) {
            printf("Eroare la realocare dinamica!");
            free(a);
            fclose(f);
            exit(-1);
        }
        a = temp;
        fscanf(f,"%d", &aux.id);
        char c = fgetc(f);
        fgets(aux.nume, 30, f);
        aux.nume[strlen(aux.nume) - 1] = '\0';
        fscanf(f, "%d", &aux.varsta);
        c = fgetc(f);
        fscanf(f, "%lf", &aux.salariu);
        c = fgetc(f);
        fgets(aux.departament, 30, f);
        aux.departament[strlen(aux.departament) - 1] = '\0';
        a[index] = aux;
        index++;
    }

    for (int i = 0; i < index; i++) {
        printf("%d,%s\n", a[i].id, a[i].nume);
        printf("%d,%lf\n", a[i].varsta, a[i].salariu);
        printf("%s\n", a[i].departament);
    }

    //bubblesort(a, index);
    double timp;
    starton();
    shell_sort(a, index);
    timp=startoff();
    printf("\n\nSortare dupa salariu:\n");

    for (int i = 0; i < index; i++) {
        printf("%d,%s\n", a[i].id, a[i].nume);
        printf("%d,%lf\n", a[i].varsta, a[i].salariu);
        printf("%s\n", a[i].departament);
    }

    printf("\n\nSalariu mediu:%lf", medie(a,index));
    printf("\n\nSalariu minim:%lf", mini(a,index));
    printf("\n\nSalariu maxim:%lf", maxi(a,index));


    printf("\n\nTimp de executie: %lf\n", timp);
    free(a);
    if (fclose(f) != 0) {
        printf("Eroare la inchiderea fisierului!");
        exit(-1);
    }
    return 0;
}