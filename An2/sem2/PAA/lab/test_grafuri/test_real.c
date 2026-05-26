//
// Created by student on 25/05/26.
//
#include <stdio.h>

#define NMAX 101

void prim(int n, int a[NMAX][NMAX])
  {
    int vizitat[NMAX] = {0};
    int cost_total = 0;

    vizitat[0] = 1;
    for(int step = 1; step <= n - 1; step++)
      {
        int min = 999999;
        int mini = -1;
        int minj = -1;
        for(int i = 0; i < n; i++)
          for(int j = 0; j < n; j++)
            {
              if(a[i][j] != 0 && vizitat[i] != 0 && vizitat[j] == 0 && a[i][j] < min)
                {
                  min = a[i][j];
                  mini = i;
                  minj = j;
                }
            }
        if(mini != -1 && minj != -1)
          {
            vizitat[minj] = 1;
            cost_total = cost_total + a[mini][minj];
            printf("%d - %d : %d\n", mini, minj, a[mini][minj]);
          }
      }
      printf("Cost total = %d\n", cost_total);
  }

int main(void)
  {

      int n, m;
      scanf("%d %d", &n, &m);
      int a[NMAX][NMAX] = {0};
      int i, j, P;
      for(int k = 0; k < m; k++)
        {
            scanf("%d %d %d", &i, &j, &P);
            a[i][j] = P;
            a[j][i] = P;
        }
      prim(n, a);
      return 0;
  }

