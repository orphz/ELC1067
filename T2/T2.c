#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Feito no editor de texto do Ubuntu
//Compilado com GCC

int linhas()
{
    FILE *f = fopen("Alunos.txt", "r");
    int c, quant=0;

    while ((c=fgetc(f))!=EOF)
    {
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
	char c;
	char* nome;
	nome=(char *) malloc (50*sizeof(char));
	
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
		nomes[linha]=(char *) malloc ( (strlen(nome) + 1)*sizeof(char));
		strcpy(nomes[linha], nome);
		mat[linha]=matricula;
		printf ("%s - %d - %d letras, linha %d", nomes[linha], mat[linha], i, linha+1);
		getchar(); // Printf+Getchar para Debug!
		linha++;
	}
	*n=linha;
	fclose(f);
}

/*void ler_notas(float* medias) -> FUNÇÃO ANTIGA, AGORA ESTÁ IMPLEMENTADA NA FUNÇÃO "PESQUISA".
{
    	FILE *f = fopen("Notas.txt", "r");
   	int matricula, i=0;
	float n1, n2;
	
    	while (feof(f)==0)
    	{
        	if(fscanf (f,"%d %f %f", &matricula, &n1, &n2)==0){break;}
        	medias[i]=(n1+n2)/2;
		i++;
		//printf("%f",medias[i-1]);
		//getchar();
    	}
	fclose(f);
}*/

void pesquisa(char* search, char** nomes, int* mat, int tam)
{
	printf ("oi");
	getchar();
	FILE *f=fopen("Notas.txt","r");
	int i, j, matricula;
	float n1, n2, media;
	
    	for (i=0; i<tam; i++)
    	{
        	if (strstr(nomes[i], search)!=NULL)
        	{	
        		while (feof(f)==0)
			{
				fscanf (f, "%d  %f %f", &matricula, &n1, &n2);
				if (matricula==mat[i])
				{
					media=(n1+n2)/2;
					printf ("Nome: %s - Media: %f", nomes[i], media);
					getchar();
				}
			}
        	}
    	}
	fclose(f);
}

int main (int argc, char** argv)
{
	char* search;
	search=(char *) malloc (25*sizeof(char));
	if(search==NULL){printf ("Memoria insuf!");}
	if (argc>1)
	{
		strcpy(search, argv[1]);
	}

	int tam=linhas();
	
	char** nomes;
	int* mat;
	int n;
	int i;
	float* medias;

	mat=(int *) malloc (tam*sizeof(int));
	if (mat==NULL){printf ("Memoria insuf.");}

	medias=(float *) malloc (tam*sizeof(float));
	if (medias==NULL){printf ("Memoria insuf.");}

	nomes=(char **) malloc (tam*sizeof(char*));
	if (nomes==NULL){printf ("Memoria insuf.");}

	ler_alunos(mat, nomes, &n);
	//ler_notas(medias); -> FUNÇÃO ANTIGA, AGORA ESTÁ IMPLEMENTADA NA FUNÇÃO "PESQUISA".
	pesquisa(search, nomes, mat, tam);

	for(i=0;i<n;i++)
	{
		free(nomes[i]);
	}
	free(search);
	free(mat);
	free(medias);
}
