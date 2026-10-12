#include <stdio.h>
#include <stdlib.h>

#define NMAX 501

void prim(int n, int a[NMAX][NMAX])
  {
      int vizitat[NMAX] = {0}; // initializam un vector in care sa contorizam daca am vizitat nodul sau nu
      int cost_total = 0; // initializam si un cost total unde vom face suma
      vizitat[1] = 1; // macarcam primul nod drept vizitat

      int max = 0; // am folosit max, maxi si maxj pentru a memora drumul dintre doua noduri cu cost maxim
      int maxi = -1, maxj = -1;

      for(int pas = 1; pas <= n - 1; pas++) // efectuam n-1 pasi
        {
            int min = 1000001;
            int mini = -1, minj = -1;
            for(int i = 1; i <= n; i++)
              for(int j = 1; j <= n; j++)
                if(a[i][j] != 0 && a[i][j] < min && vizitat[i] != 0 && vizitat[j] == 0) // verificam sa avem conexiune intre i si j, verificam ca ponderea dintre ele sa fie mai mica decat minimul curent, mai verificam ca nodul i sa fie vizitat iar nodul j sa nu fie vizitat
                  {
                      min = a[i][j];
                      mini = i;
                      minj = j;
                  }
            if(mini != -1 && minj != -1) // daca am gasit un drum
              {
                  cost_total = cost_total + min; // crestem costul total
                  vizitat[minj] = 1; // marcam noul nod drept vizitat
                  if(min > max) // aici verific si memorez ponderea maxima din secventa de drum
                  {
                    max = min;
                    maxi = mini;
                    maxj = minj;
                  }
              }
        }
        printf("%d\n", cost_total);
        if(maxi > maxj)
          printf("%d %d %d\n", max, maxj, maxi);
        else
          printf("%d %d %d\n", max, maxi, maxj);
  }

int main(int argc, char *argv[])
  {
      if(argc != 2) // verificare argumente
        {
            perror("Wrong number of arguments");
            exit(-1);
        }
       FILE *f;
       if((f = fopen(argv[1], "r")) == NULL) // deschidere fisier
         {
             perror("Error opening file");
             exit(-1);
         }

      int n, m;
      fscanf(f, "%d %d", &n, &m);
      int a[NMAX][NMAX];
      int i, j, P;
      for(int k = 0; k < m; k++) // citire matrice de adiacenta
        {
            fscanf(f, "%d %d %d", &i, &j, &P);
            if(i == j) // verificari din datele problemei
              {
                  printf("u = v!\n");
                  exit(0);
              }
            else if(i < 1)
                {
                    printf("u < 1!\n");
                    exit(0);
                }
            else if(j > n)
                  {
                      printf("j > n!\n");
                      exit(0);
                  }
            else if(P < 1 || P > 1000001)
                    {
                        printf("P > 1000001! or P < 1!\n");
                        exit(0);
                    }
            a[i][j] = P;
            a[j][i] = P;
        }
      prim(n, a); // apelam algoritmul lui PRIM, deoarece ne este garantat ca avem drum intre toate nodurile
      if(fclose(f) != 0)
        {
            perror("Error closing file");
            exit(-1);
        }
  }