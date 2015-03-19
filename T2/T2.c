#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int linhas(void)
{
    FILE *f = fopen("Alunos.txt", "r");
    int c, e_linha=0, quant=0;

    while ((c=fgetc(f))!=EOF)
    {
        e_linha=1;
        if (c=='\n')
        {
            quant++;
        }
    }

    if (e_linha)
    {
        quant++;
    }

    return quant;
}

int ler_alunos(int* mat, char** nomes, int* n)
{
	FILE *f = fopen("Alunos.txt", "r");
	int matricula, i, linha=0;
	char c, *nome;
	while (feof(f)!=0)
	{
		fscanf (f, "%d", &matricula);
		i=0;
		c=fgetc(f);
		while (c==' ')
		{
			c=fgetc(f);
		}
		while (c!='\n')
		{
			nome[i]=c;
			i++;
		}

		nome[i]='\0';
		strcpy(nomes[linha], nome);
		mat[linha]=matricula;
		linha++;
	}
	*n=linha;
	fclose(f);
}

void ler_notas(float* media)
{
    FILE *f = fopen("Notas.txt", "r");
    int matricula, i=0;
	float n1, n2;

    while (feof(f)!=0)
    {
        if((fscanf (f,"%d %f %f", &matricula, &n1, &n2))<0){break;}	//fscanf ~~~ < 0 para evitar erro
        media[i]=(n1+n2)/2;
        i++;
    }

	fclose(f);
}

void pesquisa(char* nome, char nomes[][50], float* media, int n)
{
	int i;
    for (i=0; i<n; i++)
    {
        if (strstr(nomes[i], nome)!=NULL)
        {
            printf ("%f %s", media[i], nomes[i]);
        }
    }
    return;
}


int main (int argc, char** argv)
{
	char *nome;
	if (argc>1)
	{
		strcpy(nome, argv[1]);
	}

    tam=linhas();

	char **nomes;
	int *mat, n, i;
	float *medias;


	mat=(int *) malloc (tam*sizeof(int));
	medias=(float *) malloc (tam*sizeof(float));
	nomes=(char **) malloc (tam*sizeof(char));
	for (i=0; i<tam; i++)
    {
        nomes[i]=(char *) malloc (tam*sizeof(char));
        if (nomes[i]==NULL)
        {
            printf ("Erro! Memória insuficiente!")
            return 0;
        }
    }

	ler_alunos(mat, nomes, &n);
	ler_notas(medias);
	pesquisa(nome, nomes, medias, n);

}
