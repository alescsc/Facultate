#include <stdio.h>
#include <stdlib.h>

#define NMAX 100

typedef struct
  {
      struct Nod *st, *dr;
      int cheie;
      int tata;
  } Nod;

  Nod* creare(int x, int t)
    {
        Nod* n = (Nod*)malloc(sizeof(Nod));
        n->cheie = x;
        n->tata = t;
        n->dr = NULL;
        n->st = NULL;
        return n;
    }

Nod* preordine(Nod* n, int t)
  {
      if (n == NULL)
          return NULL;
      if (n->cheie == t)
          return n;
      preordine(n->st, t);
      preordine(n->dr, t);
  }

Nod* insert(Nod* n, int x, int t)
        {
              if (n == NULL)
                n = creare(x, t);
              else
                if (n->cheie == t && n->st == NULL)
                n->st = insert(n->st, x, t);
              else if(n->cheie == t && n->dr == NULL)
                n->dr = insert(n->dr, x, t);
              else
                n = preordine(n, t);
        }

int main(int argc, char *argv[])
{
    if(argc != 3) // verificare argumente
    {
        perror("Wrong number of arguments");
        exit(-1);
    }
    FILE *f1;
    if((f1 = fopen(argv[1], "r")) == NULL) // deschidere fisier
    {
        perror("Error opening file");
        exit(-1);
    }

    FILE *f2;
    if((f2 = fopen(argv[2], "r")) == NULL) // deschidere fisier
    {
        perror("Error opening file");
        exit(-1);
    }
}