#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Cap[4];
char NumeRoboti[20][50];
int Legaturi[20];
int liber = 0;

void init()
{
	for(int i = 0; i < 4; i++)
		Cap[i] = -1;
}

void adauga(int cod, char* nume)
{
	strcpy(NumeRoboti[liber], nume); // v[liber] = val;
	Legaturi[liber] = Cap[cod];
	Cap[cod] = liber;
	liber++;
}

void afiseaza()
{
	for(int i = 0; i < 4; i++)
	{
		printf("\n");
		if(i == 0)
			printf("Mecanica: ");
		else
			if(i == 1)
				printf("Energie: ");
			else 
				if(i == 2)
					printf("Senzori: ");
				else 
					if(i == 3)
						printf("AI: ");
		int curent = Cap[i];
		while(curent != -1)
		{
			printf("%s ", NumeRoboti[curent]);
			curent = Legaturi[curent];
		}
	}
}

int main(void)
{
	FILE* f = NULL;
	if((f = fopen("Roboti.txt", "r")) == NULL)
	{
		perror("Eroare la deschiderea fisierului!");
		exit(-1);
	}
	init();
	int n;
	fscanf(f, "%d", &n);
	char c;
	c = fgetc(f);
	char s[100], aux1[100], aux2[100];
	while(n)
	{
		fgets(s,100,f);
		if(n != 1)
			s[strlen(s) - 1] = '\0';
		char *p = strtok(s, " ");
		int i = 0;
		while(p)
		{
			if(i == 0)
				strcpy(aux1, p);
			if(i == 1)
				strcpy(aux2, p);
			if(i == 2)
			{
				//
			}

			i++;
			p = strtok(NULL, " ");
		}
		int cod;
		if(aux2[0] == 'm')
			cod = 0;
		if(aux2[0] == 'e')
		 	cod = 1;
		if(aux2[0] == 's')
		 	cod = 2;
		if(aux2[0] == 'A')
		 	cod = 3;
		adauga(cod, aux1);
		n--;
	}
	afiseaza();
	if(fclose(f) != 0)
	{
		perror("Nu s-a putut inchide fisierul!");
		exit(-1);
	}
	return 0;
}