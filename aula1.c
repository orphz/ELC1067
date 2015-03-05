//Aula 1 - 05/03/2014

#include <stdio.h>
#include <stdlib.h>

void main (void)
{
	int mat;
	char nome[50];
	FILE *F;

	printf ("Digite seu nome:");
	scanf ("% [^\n]s", &nome);
	
	printf ("Digite sua matricula:");
	scanf ("%d", &mat);

	f = fopen ("saida.txt, "w");
	fprint (f, "%d %s\n", nome, mat);
	fclose (f);
}
