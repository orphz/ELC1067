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
		getchar();
		linha++;
		*n=linha;
	}
	free(nome);
	fclose(f);
	printf ("fim alunos");
	getchar();
}

void ler_notas(float* medias)
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
}

void pesquisa(char* search, char** nomes, float* medias, int n)
{
	int i;
    	for (i=0; i<n; i++)
    	{
        	if (strstr(nomes[i], search)!=NULL)
        	{	
        		printf ("%f %s", medias[i], nomes[i]);	
			getchar();
        	}
    	}
}

/*void pesquisa(char* search, char** nomes, float* media, int* mat, int n)
{	
	FILE *f=fopen("Notas.txt","r");
	int i=0;
	int* matricula;
	matricula=(int *) malloc (30*sizeof(int));
    	while (feof(f)==0)
    	{
        	fscanf(f, "%d * *", &matricula);
        	for (i=0;i<n;i++)
		{
			if(matricula==mat[i])
			{
				printf ("Nome: %s - Media: %f",nomes[i], medias[i]);
			}
		}
		//printf("%f",medias[i-1]);
		//getchar();
    	}
	free(matricula);
	fclose(f);
}*/


int main (int argc, char** argv)
{
	char* search;
	search=(char *) malloc (25*sizeof(char));
	if(search==NULL){printf ("Memoria insuf!");}
	if (argc>1)
	{
		strcpy(search, argv[1]);
	}

	//int tam=linhas();
	int tam=50;
	//printf ("tamanho %d\n", tam);
	
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
	ler_notas(medias);
	pesquisa(search, nomes, medias, n);

	/*for(i=0;i<n;i++)
	{
		free(nomes[i]);
	}
	free(search);
	free(mat);
	free(medias);
	*/
	return 0;
}
