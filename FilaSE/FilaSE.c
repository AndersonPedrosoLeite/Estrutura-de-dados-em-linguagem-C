#include <stdio.h>
#include <stdlib.h>
#include "FilaSE.h"

void criaFila(FilaSE *fila){
	fila->re=NULL;
	fila->frente=NULL;
}

int insere(FilaSE *fila,Dado d){
	Nodo *re,*frente , *pNodo ,*pAux ;
	pNodo = (Nodo *) malloc (sizeof (Nodo));
	if(pNodo == NULL)
		return FALTOU_MEMORIA;
	else if(fila->frente==NULL){
		pNodo->info = d;
		fila->re = pNodo;
		fila->frente = pNodo;
		fila->re->prox = NULL;
		return SUCESSO;
	}
	else{
		pAux=fila->re;
		while(pAux->prox!=NULL){
		pAux = pAux->prox;
		}
		pNodo->info=d;
		pNodo->prox=NULL;
		pAux->prox=pNodo;
		return SUCESSO;
		}
	}



int retira(FilaSE *fila,Dado *d){
	Nodo *filaTemp;
	if(fila->frente==NULL){
		return FILA_VAZIA;
	}else{
		*d=fila->frente->info;
		filaTemp=fila->frente;
		fila->frente=fila->frente->prox;
		free(filaTemp);
		return SUCESSO;
	}
}

int quantidadedeNodos(FilaSE *fila){
	Nodo *pAux;
	int c = 0;
	pAux = fila->frente;
		while(pAux!=NULL){
			c++;
			pAux = pAux->prox;
		}
		return c;
}

int situacaodaFila(FilaSE fila){
	if(fila.frente == NULL){
		return FILA_VAZIA;
	}else{
		return SUCESSO;
	}
}

int consultaFrente(FilaSE fila, Dado *d){
		Nodo *pAux;
		pAux = fila.frente;
		if(pAux == NULL)
			return FILA_VAZIA;
		else{
			*d = pAux->info;
			return SUCESSO;
		}
}


void exibefila(FilaSE fila){
	Nodo *pAux;
	pAux = fila.frente;
	printf("\nInicio: %p \n", fila.frente);
    printf("Exibindo a Lista\n");
    printf("[EndNodo] [cod] [peso] [EndProx]\n");
    while(pAux!=NULL){
    	printf("%p - %d %.2f - %p\n", pAux, pAux->info.cod, pAux->info.peso, pAux->prox);
           pAux = pAux->prox;
	}
}

void lerArquivo(FilaSE *fila){
	FILE *stream; char filase[20];Dado d;
	strcpy(filase,"filase.txt");
		if((stream = fopen(filase,"r"))==NULL)
			printf("\nNao foi possivel abrir %s\n",filase);
		else{
			while(fscanf(stream," %d %f\n", &d.cod, &d.peso) != EOF)
				insere(fila,d);
			fclose(stream);
			printf("\nLeitura do arquivocrealizada com sucesso!\n");
		}
}

void gravaArquivo(FilaSE *fila){
	FILE *stream;
	char filase[20];
		int i,n;
	Nodo *pAux;
	
	strcpy(filase,"filase.txt");
	
	if((stream = fopen(filase,"w"))==NULL)
		printf("\nNao foin possivel abrir %s\n",filase);
	else{
		for(pAux=fila->frente;pAux!=NULL;pAux=pAux->prox)
		fprintf(stream,"%d %.2f\n",pAux->info.cod,pAux->info.peso);
	fclose(stream);
		printf("\nGravacao realizada com sucesso!\n");
	}
}




//frente=frente->prox//
