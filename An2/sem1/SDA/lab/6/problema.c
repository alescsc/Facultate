//
// Created by alex_ on 11/8/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 15
/*
 *smecherie=salar/varsta
 *1.sa se sorteze cresc dupa smecherie, folosind un alg eficient in situ. Sa se specifice daca alg ales e stabil.
 *2.sa se afiseze primele si ultimele 5 pozitii
 *3.sa se puna toti angajatii sub 40 ani inainte tuturor celor peste 40.Sa fie cat mai eficient nu ma intereseaza de stabilitate, sau sa fie sortati.
 *4.sa se afizeze cati sunt <=40, cati peste
 *
 *
 *sa se sorteze doar primii 100 dupa salariu fct partial_sort(arr,n,k) care returneaza doar primele k elem cele mai mici, fara a sorta intreg tabloul//putem in alt vect, analizati complexitatea comparativ cu o sortare completa, quicksort
 */

typedef struct Angajati
{
  int id, varsta;
  char nume[30], departament[30];
  double salariu;
  double smecherie;
}Angajati;

void swap(Angajati *a, Angajati *b)
{
  Angajati aux=*a;
  *a=*b;
  *b=aux;
}

void quicksort(Angajati *a, int prim, int ultim)
{
  int stanga=prim+1;
  int dreapta=ultim;

  swap(&a[prim],&a[(prim+ultim)/2]);

  Angajati pivot=a[prim];
  while(stanga<=dreapta)
  {
    while (stanga<= ultim && a[stanga].smecherie<pivot.smecherie)
      stanga++;
    while (dreapta >= 0 && pivot.smecherie<a[dreapta].smecherie)
      dreapta--;
    if (stanga<dreapta)
      swap(&a[stanga++],&a[dreapta--]);
    else
      stanga++;
  }
  swap(&a[dreapta],&a[prim]);
  if (prim<dreapta-1)
    quicksort(a,prim,dreapta-1);
  if (dreapta+1<ultim)
    quicksort(a,dreapta+1,ultim);
}

void quicksort2(Angajati *a, int prim, int ultim) {
  int stanga=prim;
  int dreapta=ultim;
  while (stanga<=dreapta) {
    while (stanga <= ultim && a[stanga].varsta < 40)
      stanga++;
    while (dreapta >= 0 && a[dreapta].varsta > 40)
      dreapta--;
    if (stanga<dreapta)
      swap(&a[stanga++],&a[dreapta--]);
    else
      stanga++;
  }
}


int main(int argc, char *argv[])
{
  if(argc!=2)
    {
      printf("nr de argumente incorect");
      exit(-1);
    }
  FILE *f=fopen(argv[1],"r");
  if(f==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  Angajati aux, *a=NULL;
  a=(Angajati*)malloc(sizeof(Angajati));
  int i=0;
  for (int k=0; k<N; k++)
    {
      Angajati *temp=realloc(a,(i+1)*sizeof(Angajati));
      if(temp==NULL)
        {
          perror(NULL);
          free(a);
          exit(-1);
        }
      a=temp;

     fscanf(f,"%d",&aux.id);
      char c=fgetc(f);
      fgets(aux.nume,30,f);
      aux.nume[strlen(aux.nume)-1]='\0';
      fscanf(f,"%d",&aux.varsta);
      c=fgetc(f);
      fscanf(f,"%lf",&aux.salariu);
      c=fgetc(f);
      fgets(aux.departament,30,f);
      aux.departament[strlen(aux.departament)-1]='\0';
      aux.smecherie=aux.salariu/aux.varsta;
      a[i]=aux;
      i++;
    }

  for(int j=0;j<i;j++)
    {
      printf("%d, %s\n%d,%lf\n%s\n", a[j].id, a[j].nume, a[j].varsta, a[j].salariu, a[j].departament);
    }

 quicksort(a,0,N-1);

  for(int j=0;j<i;j++)
  {
    printf("%d, %s\n%d,%lf\n%s\n%lf\n", a[j].id, a[j].nume, a[j].varsta, a[j].salariu, a[j].departament, a[j].smecherie);
  }

  printf("Primele 5 pozitii:\n\n");
  for(int j=0;j<6;j++)
  {
    printf("%d, %s\n%d,%lf\n%s\n%lf\n", a[j].id, a[j].nume, a[j].varsta, a[j].salariu, a[j].departament, a[j].smecherie);
    printf("\n");
  }

  printf("Ultimele 5 pozitii:\n\n");
  for(int j=i-1;j>i-6;j--)
  {
    printf("%d, %s\n%d,%lf\n%s\n%lf\n", a[j].id, a[j].nume, a[j].varsta, a[j].salariu, a[j].departament, a[j].smecherie);
    printf("\n");
  }

  quicksort2(a,0,N-1);
  printf("\n\nSortare angajati dupa varsta de 40 de ani: \n");
  for(int j=0;j<N;j++)
  {
    printf("%d, %s\n%d,%lf\n%s\n%lf\n", a[j].id, a[j].nume, a[j].varsta, a[j].salariu, a[j].departament, a[j].smecherie);
    printf("\n");
  }

  free(a);
  if (fclose(f) != 0) {
    printf("Error closing file\n");
    exit(-1);
  }
  return 0;
}