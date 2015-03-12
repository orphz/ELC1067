#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pesquisar_alunos (int* mat, char** nomes, int* n, char** nomes_pesquisa)
{
	FILE *F = fopen("alunos.txt", "r");
	int matricula, i, linha=0, j=0;
	int* achado;
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
			nome[i]=c;
			i++;
		}

		nomes[i]='\0';
		strcpy(nomes[linha], nome);
		mat[linha]=matricula;
		linha++;
	}
	*n=linha;
	fclosef(F);
}

int pesquisa (char** nomes, char** nome_pesquisa, int* n)
{
    int mat_found;
    for (i=0; i<=n; i++)
    {
        if (strstr(nomes[i], nome_pesquisa)!=NULL)
        {
            mat_found[i]=mat[i];
        }
    }
    return mat_found;
}

void ler_notas (int* mat_found, int* n)
{
    FILE *F = fopen("alunos.txt", "r");
    int i=0;
    int* matricula, n1, n2, nf;
    while (i<n)
    {
        fscanf (f,"%d" "%f" "%f", &matricula[i], &n1[i], &n2[i]);
        nf[i]=(n1[i]+n2[i])/2;
        i++;
    }
}

int main (int argc, char **argv)
{
	char *nome;
	char nomes[50][50];
	char nomes_pesquisa[50][50];
	int mat[50];
	int *notas;

	if(argc>0)
	{
		nome=argv[1];
	}

}
