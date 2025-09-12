#include <stdio.h>

int n, v[20];

int valid(int k)
{
  for(int i = 0; i<k; i++)
    if(v[i] == v[k])
      return 0;
  return 1;
}

int solutie(int k)
{
  return k == n-1;
}

void tipar()
{
  for(int i = 0; i < n; i++)
    printf("%d ", v[i]);
  printf("\n");
}
void back(int k)
{
  for(int i = 1; i<=n; i++)
  {
    v[k]=i;
    if(valid(k))
      if(solutie(k))
        tipar();
      else
        back(k+1);
  }
}

int main(void)
{
  scanf("%d", &n);
  back(0);
  return 0;
}