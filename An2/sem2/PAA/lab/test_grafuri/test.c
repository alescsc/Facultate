//
// Created by alex_ on 5/19/2026.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODURI 50

void parcurgere_adancime(int nod, int n, int a[MAX_NODURI][MAX_NODURI], int vizitat[])
{
    vizitat[nod] = 1;
    printf("%d ", nod); // il afisam
    for (int i = 1; i <= n; i++) // verificam daca are muchie cu celelalte noduri
    {
        if (vizitat[i] == 0 && a[nod][i] != 0)
            parcurgere_adancime(i, n, a, vizitat); // apelam recursiv pe urmatorul nod
    }
}

void arbore_acoperire(int nod, int n, int a[MAX_NODURI][MAX_NODURI], int vizitat[])
{
    vizitat[nod] = 1;

    for (int i = 1; i <= n; i++)
        if (vizitat[i] == 0 && a[nod][i] != 0)
        {
            printf("%d - %d ", nod, i);
            arbore_acoperire(i, n, a, vizitat);
        }
}

void parcurgere_cuprindere(int nod, int n, int a[MAX_NODURI][MAX_NODURI])
{
    int vizitat[MAX_NODURI] = {0}; // initializam vector pentru vizitat si coada
    int coada[MAX_NODURI] = {0};
    int prim = 0, ultim = 0;

    coada[ultim] = nod; // punem primul nod in coada
    vizitat[nod] = 1; // il marcam ca vizitat

    printf("4) Parcurgere in latime de la nodul %d:\n", nod);

    while (prim <= ultim) // cat timp avem elemente in coada
    {
        int nod_curent = coada[prim]; // luam primul din coada
        prim++; // apoi il stergem din coada

        printf("%d ", nod_curent); // il afisam

        for (int i = 1; i <= n; i++) // ii adaugam vecinii in coada daca nu au fost deja vizitati
            if (vizitat[i] == 0 && a[nod_curent][i] != 0)
            {
                vizitat[i] = 1;
                ultim++;
                coada[ultim] = i;
            }
    }
    printf("\n");
}

void prim(int n, int a[MAX_NODURI][MAX_NODURI])
{
    int vizitat[MAX_NODURI] = {0};
    int cost_total = 0;
    vizitat[1] = 1;

    printf("6) Arborele de acoperire minim (Algoritmul lui prim):\n");
    for (int pas = 1; pas <= n - 1; pas++) // n - 1 pasi
    {
        int min = 999999;
        int mini = -1, minj = -1;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (a[i][j] != 0 && vizitat[i] != 0 && vizitat[j] == 0 && a[i][j] < min)
                {
                    min = a[i][j];
                    mini = i;
                    minj = j;
                }
        if (mini != -1 && minj != -1)
        {
            vizitat[minj] = 1;
            cost_total = cost_total + min;
            printf("Muchia (%d - %d) cu ponderea: %d\n", mini, minj, min);
        }
    }
    printf("Cost total: %d\n", cost_total);
}

void kruskal(int n, int a[MAX_NODURI][MAX_NODURI])
{
    int vizitat[MAX_NODURI] = {0};
    int cost_total = 0;

    for (int i = 1; i <= n; i++) // diferenta fata de PRIM, initializam fiecare nod in propiul subarbore
        vizitat[i] = i;

    printf("7) Arborele de acoperire minim (Algoritmul lui Kruskal):\n");
    for (int pas = 1; pas <= n - 1; pas++) // n - 1 pasi
    {
        int min = 999999;
        int mini = -1, minj = -1;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (a[i][j] != 0 && vizitat[i] != vizitat[j] && a[i][j] < min) // diferenta fata de PRIM, verificam ca nodurile sa fie in subarbori diferiti
                {
                    min = a[i][j];
                    mini = i;
                    minj = j;
                }
        if (mini != -1 && minj != -1)
        {
            cost_total = cost_total + min;
            printf("Muchia (%d - %d) cu ponderea: %d\n", mini, minj, min);

            int pred = vizitat[minj];
            int cur = vizitat[mini];

            for (int k = 1; k <= n; k++) // diferenta fata de PRIM, mutam nodurile din subarborele vechi in cel nou
                if (vizitat[k] == pred)
                        vizitat[k] = cur;
        }
    }
    printf("Cost total: %d\n", cost_total);
}

void djikstra(int start, int n, int a[MAX_NODURI][MAX_NODURI])
{
    int dist[MAX_NODURI];
    int vizitat[MAX_NODURI] = {0};
    int INF = 999999;

    for (int i = 1; i <= n; i++)
        dist[i] = INF;

    dist[start] = 0;
    printf("8) Algoritmul Dijkstra (Drumuri minime de la nodul %d):\n", start);

    for (int pas = 1; pas <= n - 1; pas++)
    {
        int min = INF;
        int u = -1;
        for (int i = 1; i <= n; i++)
            if (vizitat[i] == 0 && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        if (u == -1) break;

        vizitat[u] = 1;
        for (int v = 1; v <= n; v++)
            if (vizitat[v] == 0 && a[u][v] != 0 && dist[u] + a[u][v] < dist[v])
                dist[v] = dist[u] + a[u][v];
    }
    for (int i = 1; i <= n; i++)
        if (dist[i] == INF)
            printf("Drum %d -> %d: Infinit (Inaccesibil)\n", start, i);
        else
            printf("Drum %d -> %d: Cost %d\n", start, i, dist[i]);
}

void floyd(int n, int a[MAX_NODURI][MAX_NODURI])
{
    int D[MAX_NODURI][MAX_NODURI];
    int INF = 999999;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j)
                D[i][j] = 0;
            else if (a[i][j] != 0)
                D[i][j] = a[i][j];
            else
                D[i][j] = INF;

    printf("9) Algoritmul Floyd-Warshall (Matricea drumurilor minime):\n");
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (D[i][k] != INF && D[k][j] != INF)
                    if (D[i][j] > D[i][k] + D[k][j])
                        D[i][j] = D[i][k] + D[k][j];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            if (D[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", D[i][j]);
        printf("\n");
    }
}


int main(void)
{

    FILE* f = NULL;
    if ((f = fopen("grafuri.txt", "r")) == NULL) {
        perror("Eroare la deschiderea fisierului!\n");
        exit(-1);
    }

    int n, m, a[MAX_NODURI][MAX_NODURI] = {0};
    fscanf(f,"%d", &n); // nr noduri
    fscanf(f,"%d", &m); // nr muchii
    int i, j, P;

    for(int k = 0; k < m; k++) // citim muchiile 
    {
        fscanf(f,"%d %d %d", &i, &j, &P); // intre i si j se pune muchia cu ponderea P
        a[i][j] = P;
        a[j][i] = P; // se pune daca e neorientat
    }

    printf("1) Matricea de adiacenta: \n");
    for(i = 1; i <= n; i++) // afisare
    {
        for(j = 1; j <= n; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }

    printf("\n");
    printf("2) Parcurgere in adancime: \n");
    int vizitat[MAX_NODURI] = {0};
    parcurgere_adancime(1, n, a, vizitat);
    printf("\n\n");

    // trecem la afisarea si numararea componentelor conexe
    printf("3) Componente conexe:\n");
    for (i = 1; i <= n; i++)
        vizitat[i] = 0;
    int CC = 0; // nr. componente conexe
    for(i = 1; i <= n; i++)
    {
        if(vizitat[i] == 0) // verificam daca nodul e vizitat, daca nu e, inseamna ca suntem intr o noua componenta conexa
        {
            CC++; // contorizam
            printf("Componenta conexa %d:\n", CC);
            parcurgere_adancime(i, n, a, vizitat); // parcurgem componenta conexa respectiva
            printf("\n");
        }
    }
    printf("Numar total componente conexe: %d\n\n", CC);

    //parcurgere latime
    parcurgere_cuprindere(1, n, a);

    //arbore acoperire
    for (i = 1; i <= n; i++)
        vizitat[i] = 0;
    printf("\n5) Arbore de acoperire din nodul 1:\n");
    arbore_acoperire(1, n, a, vizitat);

    //alg lui prim - merge doar daca avem o singura componenta conexa
    printf("\n\n");
    prim(n, a);

    //alg lui kruskal - merge si daca avem mai multe componente conexe
    printf("\n\n");
    kruskal(n, a);

    printf("\n\n");
    djikstra(1, n, a);

    printf("\n\n");
    floyd(n, a);

    if (fclose(f) != 0) {
        perror("Eroare la inchiderea!\n");
        exit(-1);
    }
    return 0;
}