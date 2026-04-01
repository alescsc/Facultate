#include <stdio.h>
#include <stdlib.h>

typedef struct Nod
{
  char data;
  int frecv;
  struct Nod *st, *dr;
} Nod;

Nod* creare(char data, int frecv)
{
  Nod* Nou = (Nod*)malloc(sizeof(Nod));
  Nou->data = data;
  Nou->frecv = frecv;
  Nou->st = Nou->dr = NULL;
  return Nou;
}

int main(int argc, char *argv[])
{
  if(argc != 3)
    {
      printf("Nr incorect de parametrii");
      exit(-1);
    }
  FILE* f = NULL;
  if((f = fopen(argv[1], "r")) == NULL)
    {
      perror("Eroare la deschiderea fisierului!");
      exit(-1);
    }
  int frecv[256] = {0};
  int c;

  while((c = fgetc(f)) != EOF)
    if(c != '\n' && c != ' ')
      frecv[c]++;

  if(fclose(f) != 0)
    {
      perror("Eroare la inchiderea fisierului!");
      exit(-1);
    }

  FILE* g = NULL;
  if((g = fopen(argv[2], "w")) == NULL)
    {
      perror("Eroare la deschiderea fisierului!");
      exit(-1);
    }

  Nod* noduri[256] = {NULL};

  for(int i = 0; i < 256; i++)
    if(frecv[i] > 0)
      {
	char aux = (char)i;
	fprintf(g, "%c - %d\n", aux, frecv[i]);
	noduri[i] = creare(aux, frecv[i]);
      }


  if(fclose(g) != 0)
    {
      perror("Eroare la inchiderea fisierului!");
      exit(-1);
    }
  return 0;
}
