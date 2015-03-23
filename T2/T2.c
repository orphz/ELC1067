#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Feito no editor de texto do Ubuntu
//Tabulação de tamanho 4

int linhas()
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
    return quant;
}

void ler_alunos(int* mat, char** nomes, int* n)
{	
	FILE *f = fopen("Alunos.txt", "r");
	int matricula, i=0, linha=0;
	char c, *nome;

	while (feof(f)==0)
	{	
		fscanf (f, "%d", &matricula);
		c=fgetc(f);
		while (c==' ')
		{
			c=fgetc(f);
		}
		i=0;
		while (c!='\n')
		{	
			nome[i]=c;
			c=fgetc(f);
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

void ler_notas(float* medias)
{
    FILE *f = fopen("Notas.txt", "r");
    int matricula, i=0;
	float n1, n2;
	
    while (feof(f)==0)
    {
        if((fscanf (f,"%d %f %f", &matricula, &n1, &n2))<0){printf("erro"); break;} //fscanf ~~~ < 0 para evitar erro
        medias[i]=(n1+n2)/2;
		i++;
    }
	fclose(f);
}

void pesquisa(char* search, char** nomes, float* media, int n)
{
	int i;
    for (i=0; i<n; i++)
    {
        if (strstr(nomes[i], search)!=NULL)
        {	
            printf ("%f %s", media[i], nomes[i]);
			getchar();		
        }
    }
}


int main (int argc, char** argv)
{
	char *nome;
	nome=(char *) malloc (30*sizeof(char));
	if(nome==NULL){printf ("Memoria insuf!");}
	if (argc>1)
	{
		strcpy(nome, argv[1]);
	}


	//int tam=linhas();
	int tam=610;
	char** nomes;
	int* mat, n;
	int i;
	float* medias;

	mat=(int *) malloc (tam*sizeof(int));
	if (mat==NULL){printf ("Memoria insuf.");}
	medias=(float *) malloc (tam*sizeof(float));
	if (medias==NULL){printf ("Memoria insuf.");}
	nomes=(char **) malloc (tam*sizeof(char));
	for (i=0; i<tam; i++)
    {
        nomes[i]=(char *) malloc (tam*sizeof(char));
        if (nomes[i]==NULL)
        {
            printf ("Erro! Memória insuficiente!");
            return 0;
        }
    }
	if (nomes==NULL){printf ("Memoria insuf.");}

	ler_alunos(mat, nomes, &n);
	ler_notas(medias);
	pesquisa(nome, nomes, medias, n);

}
