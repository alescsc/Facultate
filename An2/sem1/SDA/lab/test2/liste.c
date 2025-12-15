#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int info;
  struct Node* next;
}Node;

Node* nou(int info, Node* urm)
{
  Node* nou=malloc(sizeof(Node));
  if(nou==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  nou->info=info;
  nou->next=urm;
  return nou;
}

Node* adauga_sf(int info, Node* lista)
{
  if(lista==NULL)
    return nou(info, NULL);
  else
    {
      Node* nod=nou(info, NULL);
      if(nod==NULL)
	{
	  perror(NULL);
	  exit(-1);
	}
      Node* p=lista;
      for(; p->next!=NULL; p=p->next);
      p->next=nod;
    }
  return lista;
}

Node* adauga_inc(int info, Node* lista)
{
  Node* nod=nou(info, lista);
  if(nod==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  lista=nod;
  return lista;
}

void afisare(Node* lista)
{
  Node* p=lista;
  while(p!=NULL)
    {
      printf("%d ", p->info);
      p=p->next;
    }
}

Node* sterge(int info, Node* lista)
{
  if(lista==NULL)
    return NULL;
  if(lista->info==info)
    {
      Node* aux=lista;
      lista=lista->next;
      free(aux);
      return lista;
    }
  for(Node* prev=lista, *p=lista->next;p!=NULL;p=p->next, prev=prev->next)
    {
      if(p->info==info)
       {
	if(p->next==NULL)
	{
	  prev->next=NULL;
	  free(p);
	  return lista;
	}
      else
	{
	  prev->next=p->next;
	  free(p);
	  return lista;
	}
       }
    }
  return lista;
}

int main()
{
  Node* lista=NULL;
  Node* lista1=NULL;
  int x, y;
  for(int i=0;i<4;i++)
    {
      scanf("%d", &x);
      lista=adauga_sf(x, lista);
    }
  /*for(int i=0;i<3;i++)
    {
      scanf("%d", &y);
      lista1=adauga_inc(y, lista1);
      }*/
  afisare(lista);
  printf("\n");
  //afisare(lista1);
  printf("\n");
  lista=sterge(5, lista);
  afisare(lista);
  return 0;
}