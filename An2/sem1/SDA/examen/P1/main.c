#include <stdio.h>
#include <stdlib.h>


typedef struct { // structura data
    int id;
    int zbor;
    int prioritate;
    int pret;
} Rezervare;

void swap(Rezervare *a, Rezervare *b) { // functie swap pentru a face interschimbarea
    Rezervare temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(Rezervare *arr, int prim, int ultim) { // algoritm quicksort, eficienta O(n*log n)
    if (prim > ultim) {
        return;
    }

    int stanga = prim + 1;
    int dreapta = ultim;
    swap(&arr[prim], &arr[(prim + ultim) / 2]); // punem pivot pe prima poz

    Rezervare pivot = arr[prim];

    while (stanga <= dreapta) {
        while (stanga <= ultim && arr[stanga].prioritate < pivot.prioritate) {
            stanga++; // gasim primul elem din stanga care nu e potrivit
        }
        while (dreapta >= prim && arr[dreapta].prioritate > pivot.prioritate) {
            dreapta--; // gasim primul elem din dreapta care nu e potrivit
        }

        if (stanga < dreapta) {
            swap(&arr[stanga++], &arr[dreapta--]); // le interschimbam
        }
        else
            stanga++;
    }

    swap(&arr[prim], &arr[dreapta]); // punem la loc pivotul si continuam algoritmul

    if (prim < dreapta - 1)
        quicksort(arr, prim, dreapta - 1);
    if (dreapta + 1 < ultim)
        quicksort(arr, dreapta + 1, ultim);
}

/*
    pentru a implementa multilista am folosit o lista simplu inlantuita drept lista principala
    apoi o coada de tip FIFO folosind tot o lista simplu inlantuita care adauga elem
    la final si le scoate de la cap

    eficienta pentru a adauga si a scoate elemente este O(1)
*/
typedef struct Nod { // structura pentru un nod
    Rezervare data;
    struct Nod *next;
} Nod;

typedef struct Lista { // structura pentru lista
    Nod *prim;
    Nod *ultim;
} Lista;

Nod* creare(Rezervare val) { // functie de a crea un nod
    Nod *n = (Nod *)malloc(sizeof(Nod));
    n->data = val;
    n->next = NULL;
    return n;
}

void adauga(Lista *lista, Rezervare val) { // functie de a adauga la final un nod
    Nod *n = creare(val);

    if (lista->prim == NULL) { // daca lista este goala
        lista->prim = n;
        lista->ultim = n;
    }
    else { // daca lista are deja elemente
        lista->ultim->next = n;
        lista->ultim = lista->ultim->next;
    }
}

void afisare(Lista *lista) { // afisare lista
    Nod *n = lista->prim;
    while (n != NULL) {
        printf(" %d ", n->data.zbor);
        if (n->next != NULL)
            printf("->" );
        n = n->next;
    }
}

void golire(Lista *lista) { // functie pentru a goli lista
    Nod *n = lista->prim;
    while (n != NULL) {
        Nod* current = n;
        n = n->next;
        free(current);
    }

    lista->ultim = NULL;
    lista->prim = NULL;
    free(lista);
}

int Sum, k; // rezolvarea cerintei recursivitate unde calculam suma si nr de elem
// cu prioritatea P

int recursivitate(Rezervare *arr, int size, int P) {
    if (size == -1)
        return 0;
    if (arr[size].prioritate >= P) {
        Sum += arr[size].pret;
        k++;
    }
    return recursivitate(arr, size-1, P);
}


int main(void) {
    FILE *f = NULL;

    if ((f = fopen("rezervari.in", "r")) == NULL) {
        perror("Eroare la deschiderea fisierului!");
        exit(-1);
    } // deschidere fisier

    int size;
    fscanf(f, "%d", &size);
    int buffer;
    fscanf(f, "%d", &buffer);
    fscanf(f, "%d", &buffer);
    Rezervare rezervare[size];
    int index = 0;

    while (size) { // citire si punere in tablou structura
        fscanf(f, "%d", &rezervare[index].id);
        fscanf(f, "%d", &rezervare[index].zbor);
        fscanf(f, "%d", &rezervare[index].prioritate);
        fscanf(f, "%d", &rezervare[index].pret);
        size--;
        index++;
    }

    size = index;
    printf("Tablou initial: \n"); // afisare a tabloului initiala
    for (int i = 0; i < size; i++) {
        printf("%d %d %d %d\n", rezervare[i].id, rezervare[i].zbor, rezervare[i].prioritate, rezervare[i].pret);
    }

    quicksort(rezervare, 0, size - 1);

    for (int i = 0; i < size - 1; i++) {  // impunere a doua conditie de sortare cu Bubble, O(n^2)
        for (int j = i + 1; j < size; j++) {
            if (rezervare[i].prioritate == rezervare[j].prioritate && rezervare[i].pret > rezervare[j].pret) {
                swap(&rezervare[i], &rezervare[j]);
            }
        }
    }

    printf("\n\nA) Sortare:\n"); // afisare
    for (int i = 0; i < size; i++) {
        printf("%d %d %d %d\n", rezervare[i].id, rezervare[i].zbor, rezervare[i].prioritate, rezervare[i].pret);
    }

    Lista* lista = (Lista *)malloc(sizeof(Lista)); // creare lista
    lista->prim = NULL;
    lista->ultim = NULL;

    Lista* coada = (Lista *)malloc(sizeof(Lista)); // creare coada
    coada->prim = NULL;
    coada->ultim = NULL;

    for (int i = 0; i < size; i++) { // adaugare elem in coada
        adauga(coada, rezervare[i]);
    }

    for (int i = 0; i < size; i++) { // sortare pentru lista folosind Bubble, O(n^2)
        for (int j = i + 1; j < size; j++) {
            if (rezervare[i].id > rezervare[j].id) {
                swap(&rezervare[i], &rezervare[j]);
            }
        }
    }

    for (int i = 0; i < size; i++) {
        adauga(lista, rezervare[i]);
    }

    // afisari si goliri pentru lista si coada
    printf("\n\nB) Multilista: \nLista: ");
    afisare(lista);
    printf("-> NULL\n");
    golire(lista);
    printf("Coada: ");
    afisare(coada);
    printf("\n");
    golire(coada);

    printf("\n\n"); // rezolvare cerinta cu recursivitate

    int P = 3;
    recursivitate(rezervare, size, P);

    printf("C) Recursivitate: \n");
    printf("Suma = %d\n", Sum);
    printf("Nr. rezervari cu prioritate >=%d: %d", P, k);
    printf("\n");

    if (fclose(f) != 0) {
        perror("Eroare la inchiderea fisierului!");
        exit(-1);
    }

}