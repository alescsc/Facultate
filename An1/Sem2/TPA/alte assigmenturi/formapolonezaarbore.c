#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node 
{
	char val;
	struct node *left, *right;
} Node;

Node* create(char val, Node *left, Node *right)
{
	Node* nod = malloc(sizeof(Node));
	nod->val = val;
	nod->left = left;
	nod->right = right;
	return nod;
}

Node* construire_arbore(char *ex)
{
	Node* stack[100];
	int top = 0;
	int i = 0;
	while(ex[i])
	{
		char c = ex[i];
		if(c >= 'a' && c <='z')
			stack[top++] = create(c, NULL, NULL);
		else
		{
			Node* right = stack[--top];
			Node* left = stack[--top];
			stack[top++] = create(c, left, right);
		}
		i++;
	}
	return stack[0];
}

int evaluare(Node* rad, int* v)
{
	if(rad->left == NULL && rad->right == NULL)
		return v[rad->val - 'a'];
	int l = evaluare(rad->left, v);
	int r = evaluare(rad->right, v);
	if(rad->val == '+')
		return l + r;
	else
		if(rad->val == '-')
			return l - r;
		else
			if(rad->val == '*')
				return l*r;
			else
				if(rad->val == '/')
					return l/r;
	return 0;
}

void citire(Node* rad, int* v)
{
	if(rad == NULL)
		return;
	if(rad->left == NULL && rad->right == NULL)
	{
		int index = rad->val - 'a';
		if(v[index] == 100001)
		{
			printf("%c = ", rad->val);
			scanf("%d", &v[index]);
		}
	}
	citire(rad->left, v);
	citire(rad->right, v);
}

void free_arbore(Node* rad)
{
	if(rad == NULL)
		return;
	free_arbore(rad->left);
	free_arbore(rad->right);
	free(rad);
}

void tipar(Node* rad)
{
	if(rad)
	{
		if(rad->left || rad->right)
			printf("(");
		tipar(rad->left);
		printf("%c", rad->val);
		tipar(rad->right);
		if(rad->left || rad->right)
			printf(")");
	}
}

int main(void)
{
	char ex[256];
	int v[26] = {0};
	printf("Forma poloneza: ");
	fgets(ex, sizeof(ex), stdin);
	for(int i = 0; i < 26; i++)
		v[i] = 100001;
	Node* rad = construire_arbore(ex);
	citire(rad, v);
	printf("Expresia:");
	tipar(rad);
	printf("\n");
	int rezultat = evaluare(rad, v);
	printf("Rezultat: %d\n", rezultat);
	free_arbore(rad);
	return 0;
}