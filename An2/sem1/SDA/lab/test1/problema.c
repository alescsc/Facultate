//
// Created by alex_ on 11/8/2025.
//

// Sortare primele pozitii sa fie angajati sub 40 de ani, toate tipurile de sortari

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Angajati {
    char nume[30], departament[30];
    int varsta, id;
    double salariu;
} Angajati;

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Nr invalid de argumente!");
        exit(-1);
    }

    FILE *f = NULL;
    if ((f = fopen(argv[1], "r")) == NULL) {
        printf("File Not Found\n");
        exit(-1);
    }

    Angajati *a = NULL;
    a = (Angajati*)malloc(sizeof(Angajati));
    Angajati aux;
    int index = 0;

    while (fscanf(f,"%d", &aux.id) != EOF) {
        Angajati *temp = realloc(a, (index + 1)*sizeof(Angajati));
        if (temp == NULL) {
            printf("Eroare la realocare dinamica!");
            free(a);
            fclose(f);
            exit(-1);
        }
        a = temp;
        char c;
        fscanf(f, "%c", &c);
        fgets(aux.nume, 30, f);
        aux.nume[strlen(aux.nume) - 1] = '\0';
        fscanf(f, "%d", &aux.varsta);
        fscanf(f, "%c", &c);
        fscanf(f, "%lf", &aux.salariu);
        fscanf(f, "%c", &c);
        fgets(aux.departament, 30, f);
        aux.departament[strlen(aux.departament) - 1] = '\0';
        a[index] = aux;
        index++;
    }

    for (int i = 0; i < index; i++) {
        printf("%d, %s \n", a[i].id, a[i].nume);
        printf("%d, %lf \n", a[i].varsta, a[i].salariu);
        printf("%s \n\n\n", a[i].departament);
    }

    free(a);
    if (fclose(f) != 0) {
        printf("Eroare la inchiderea fisierului!");
        exit(-1);
    }
    return 0;
}