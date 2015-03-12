#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ler_alunos (int* mat, char** nomes, int* n)
{
	FILE *F = fopen("alunos.txt", "r");
	int matricula, i, linha=0;
	char c, nome[50];
	while (feof(F)!=0)
	{
		fscanf (F, "%d", &matricula);
		i=0;
		c=fgetc(F);
		while (c==' ')
		{
			c=fgetc(F);
		}
		while (c!='\n')
		{
			nomes[i]=c;
			i++;
		}
		
		nomes[i]='\0';
		strcpy(nomes[linha], nome)
		linha++
	}
	*n=linha;
	fclosef(F);
}

int main (int argc, char **argv)
{
	char *nome;
	char nome[50][50]
	int mat[50], n;

	if(argc>0)
	{
		nome=argv[1];
	}

}
