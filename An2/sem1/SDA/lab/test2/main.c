#include <stdio.h>
#include <stdlib.h>

#define LMAX 15

// am implementat un priority queue folosind logica de heap pentru a avea eficienta O(log n)
// am folosit o stiva de debugging unde memoram ultimele taskuri executate
// adauga_task() are eficienta O(1)
// executa() are eficienta O(1) unde si apelul push() are eficienta tot O1
// anuleaza_ultimul() are eficienta O(log n) deoarece dupa se resorteaza priority queue-ul pentru
// a pastra prioritatiile
// listare() are eficienta O(n) deoarece se afiseaza din coada si din stiva toate elementele pe
// rand
// nu am stiut cum sa implementez priority queue altfel, am invatat de pe net in weekend
// in curs si lab n aveam nimic despre, sper ca e ok, din cate am inteles eu are eficienta O(log n)
// si practic se foloseste de heapuri pentru a le pune ca intr un arbore si atunci le extrage
// pe rand in cel mai eficient mod
// stiva e stiva basic din lab cu mici schimbari


typedef struct {
    int ID;
    int p;
} Elem; // element pentru stiva si coada

typedef struct {
    Elem elem[LMAX];
    int size;
} PQ; // coada

typedef struct {
    Elem corp_stiva[LMAX];
    int varf_stiva;
} stiva; // stiva

stiva st;

void push(Elem e) {
    st.corp_stiva[st.varf_stiva] = e;
    st.varf_stiva++;
} // adaugare element in stiva O(1)


Elem anuleaza_ultimul() {
    st.varf_stiva--;
    return st.corp_stiva[st.varf_stiva];
} // scoate elemet din stiva O(1)

void swap(Elem *a, Elem *b) {
    Elem t = *a;
    *a = *b;
    *b = t;
}

void init(PQ *pq) {
    pq->size = 0;
} // initializere coada

void heapify(PQ *pq, int i) {
    int st = 2*i + 1;
    int dr = 2*i + 2;

    int minim = i;

    if (st < pq->size && pq->elem[st].p < pq->elem[minim].p)
        minim = st;
    if (dr < pq -> size && pq->elem[dr].p < pq->elem[minim].p)
        minim = dr;

    if (minim != i) {
        swap(&pq->elem[minim], &pq->elem[i]);
        heapify(pq, minim);
    }
} // pt a ordona din nou coada

void adauga_task(PQ *pq, int id, int p) {
    pq->elem[pq->size].ID = id;
    pq->elem[pq->size].p = p;
    int i = pq->size;
    pq->size++;

    int parinte = (i-1)/2;

    while (i != 0 && pq->elem[parinte].p > pq->elem[i].p) {
        swap(&pq->elem[parinte], &pq->elem[i]);
        i = parinte;
        parinte = (i-1)/2;
    }
} // adauga task O(1)

Elem executa(PQ *pq) {
    Elem elem_maxim = pq->elem[0];
    pq->elem[0] = pq->elem[pq->size-1];

    pq->size--;
    push(elem_maxim);
    heapify(pq, 0);

    return elem_maxim;
}

void listare(PQ *pq)
{
    printf("Coada cu prioritate este: ");
    for (int i = 0; i < pq->size; i++)
        printf("[%d P:%d] ", pq->elem[i].ID, pq->elem[i].p);

    printf("\n\n");
    printf("Stiva cu taskuri executate: ");
    for (int i = st.varf_stiva - 1; i >= 0; i--)
        printf("%d ", st.corp_stiva[i].ID);
    printf("\n\n");
} // listare O(n)

// si afisezi din lista numele destinatiei si din coada

int main(void) {
    PQ pq;
    init(&pq);

    FILE *f = NULL;
    if ((f = fopen("Taskuri.txt", "r")) == NULL) {
        perror("Eroare la deschiderea fiserului!");
        exit(-1);
    }

    int n;
    fscanf(f, "%d", &n);
    Elem aux;

    while (n) {
        fscanf(f, "%d", &aux.ID);
        fscanf(f, "%d", &aux.p);
        adauga_task(&pq, aux.ID, aux.p);
        n--;
    }

    listare(&pq);
    executa(&pq);
    executa(&pq);
    executa(&pq);
    executa(&pq);
    executa(&pq);
    executa(&pq);

    printf("Se executa primele 6 task-uri.\n");
    listare(&pq);
    if (fclose(f) != 0) {
        perror("Eroare la inchiderea fiserului!");
        exit(-1);
    }
}