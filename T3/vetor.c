/*
 * vetor.c
 * TAD que implementa um vetor dinamico.
 *
 * The MIT License (MIT)
 * 
 * Copyright (c) 2014, 2015 João V. Lima, UFSM
 *               2005       Benhur Stein, UFSM
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "vetor.h"
#include "carta.h"
#include "memo.h"

struct vetor {
	/* gg */
	/* defina os campos da TAD vetor aqui */
	
	carta* baralho;   /* baralho - vetor de cartas */
	int n;		/* número de cartas */
	int r;
};

vetor_t* vetor_cria(void)
{	
	/* gg */
	struct vetor *vet = (struct vetor*)memo_aloca(sizeof(struct vetor));
	vet->n = 0;
	
	int i;

	vet->baralho = (carta*) memo_aloca(50*sizeof(carta));

	for (i=0; i<50; i++)
	{
		vet->baralho[i] = NULL;
	}
	return vet;
}

void vetor_destroi(vetor_t* vet)
{
	/* gg */
	memo_libera(vet->baralho);
	memo_libera(vet);	
}

int vetor_numelem(vetor_t *vet)
{
	/* gg */
	return vet->n;
}

void vetor_insere_carta(vetor_t *vet, int indice, carta c)
{
	/* gg */
	int cartas;
	cartas = vet->n-1;
	if (vet->baralho[indice] != NULL)
	{
		while (cartas != indice)
		{
			if (indice > 20)
			{
				vet->baralho = memo_realoca (vet->baralho, 100);
			}
			vet->baralho[cartas+1] = vet->baralho[cartas];
			cartas--;	
		}
	vet->baralho[cartas+1] = vet->baralho[cartas];
	vet->baralho[indice] = c; 
	vet->n++;	
	}	
	else
	{
		vet->baralho[indice]=c;
		vet->n++;
	}
}

carta vetor_remove_carta(vetor_t *vet, int indice)
{
	/* gg */
	carta card = vet->baralho[indice];
	int i;
	int j = vet->n;
	if (card==NULL){return NULL;}

	vet->r=-1;
	
	for (i=indice; i<j; i++)
	{
		vet->baralho[i] = vet->baralho[i+1];
	}
	vet->n--;
	vet->baralho[vet->n]=NULL;
	return card;
}

carta vetor_acessa_carta(vetor_t *vet, int indice)
{
	/* gg */
	return vet->baralho[indice];
}

bool vetor_valido(vetor_t *vet)
{
	/* gg */
	if (vet==NULL)	{return false;}
	else {return true;}
}
