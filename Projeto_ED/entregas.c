#include <stdio.h>
#include <stdlib.h>
#include "Entregas.h"


void crialista(ListaEntregas *lista){
	lista->inicio = NULL;
	lista->fim = NULL;
	lista->numerodeentregas = 0;
}

int insereentrega(ListaEntregas *lista, Dado d){
	Nodo *pNodo;
	pNodo = (Nodo *) malloc (sizeof (Nodo));
	if(pNodo == NULL)
		return(FALTOU_MEMORIA);
	else{
		pNodo->info = d;
		pNodo->prox = lista->inicio;
		pNodo->ant = NULL;
		
		if(lista->numerodeentregas == 0)
			lista->fim = pNodo;
		else
			lista->inicio->ant = pNodo;	
			
		lista->inicio = pNodo;
		lista->numerodeentregas++;
		return SUCESSO;
	}
}

int fretepago(ListaEntregas *lista, int cod, Dado d){
	Nodo *pNodo, *pAux;
	pNodo = (Nodo *) malloc (sizeof (Nodo)); 
	if(pNodo == NULL)
		return(FALTOU_MEMORIA);
		else if(lista->numerodeentregas == 0){
		pNodo->info = d;
		pNodo->ant = NULL;
		pNodo->prox=NULL;
		lista->inicio=pNodo;
		lista->fim=pNodo;
		lista->numerodeentregas++;
		return SUCESSO;
		}else{
		pAux = lista->fim;
		while(pAux != NULL){
			if(pAux->info.cod==cod){
				pNodo->info = d;
				if(pAux==lista->inicio){
					pNodo->ant = NULL;
					lista->inicio->ant = pNodo;
					pNodo->prox = lista->inicio;
					lista->inicio = pNodo;
				}
				else{
					pNodo->prox = pAux;
					pNodo->ant = pAux->ant;
					pAux->ant = pNodo;
					pNodo->ant->prox = pNodo;
				}
				lista->numerodeentregas++;
				return SUCESSO;
			}
			pAux = pAux->ant;
		}
		return CODIGO_INEXISTENTE;
	}
}
int fretegratis(ListaEntregas *lista, Dado d){
	Nodo *pNodo,*pAux;
	pNodo = (Nodo *) malloc (sizeof (Nodo));
	if(pNodo == NULL)
		return FALTOU_MEMORIA;
		else if(lista->numerodeentregas == 0){
		pNodo->info = d;
		pNodo->ant = NULL;
		pNodo->prox=NULL;
		lista->inicio=pNodo;
		lista->fim=pNodo;
		lista->numerodeentregas++;
		return SUCESSO;
	}
	else{
		pNodo->info = d;
		pNodo->prox=NULL;
		lista->fim->prox = pNodo;
		pNodo->ant = lista->fim;
		lista->fim = pNodo;
		lista->numerodeentregas++;
		return SUCESSO;
	}	
}	
void listadeentregas(ListaEntregas lista){
     Nodo *pAux;
     pAux = lista.inicio;
     printf("\n\tExibindo a Lista de entregas:\n");
     
     while (pAux != NULL) {
           printf(" Codigo %d  Data de entrega: %s  Nome do produto: %s  Endereco de entrega: %s \n", pAux->info.cod,pAux->info.data, pAux->info.produto,pAux->info.endereco);
           pAux = pAux->prox;
     }
     printf("\tFim: - Numero de entregas= %d\n", lista.numerodeentregas);
}

int cancelaentrega(ListaEntregas *lista, int cod, Dado *d){
	Nodo *pAux, *pTemp, *pAux2;     
	
		pAux = lista->inicio;
		while(pAux!=NULL){
			if(pAux->info.cod==cod){
				*d =pAux->info;
				pTemp= pAux;
				if(lista->numerodeentregas==1){
					lista->inicio=NULL;
					lista->fim=NULL;
				}else if(pAux==lista->inicio){
					lista->inicio=pAux->prox;
					lista->inicio->ant=NULL;
				}
				else if(pAux==lista->fim){
					excluidofim(lista,d);
				}else{
					pAux2 = pAux->prox;
					pAux = pAux->ant;
					pAux->prox=pAux2;
					pAux2->ant=pAux;
				}
				free(pTemp);
				lista->numerodeentregas--;
				return SUCESSO;
			}
			pAux=pAux->prox;
		}
		return CODIGO_INEXISTENTE;
}
int excluidofim(ListaEntregas *lista, Dado *d){
	Nodo *pAux, *pTemp;
	if(lista->inicio==NULL){
		return LISTA_VAZIA;
	}
	else if(lista->inicio->prox==NULL){
		*d=lista->inicio->info;
		pTemp=lista->inicio;
		free(pTemp);
		lista->inicio=NULL;
		lista->fim=NULL;
		lista->numerodeentregas--;
		return SUCESSO;
	}else{
		pAux=lista->inicio;
		while(pAux->prox->prox!=NULL){
			pAux = pAux->prox;
		}
		*d=pAux->prox->info;
		pTemp=pAux->prox=NULL;
		free(pTemp);
		lista->fim=pAux;
		lista->numerodeentregas--;
		return SUCESSO;
	}
}

int quantidadeentregas(ListaEntregas lista){
	int c = 0;
	Nodo *pAux;
	pAux = lista.inicio;
	while(pAux!=NULL){
		c++;
		pAux = pAux->prox	;
	}
		return c;
}

void gravaarquivo(ListaEntregas *lista){
	FILE *stream;
	char entregas[100];
		int i,n;
	Nodo *pAux;
	
	strcpy(entregas,"entregas.txt");
	if((stream=fopen(entregas,"w"))==NULL)
		printf("\nNao foi possivel abrir %s\n",entregas);
	else{
			for(pAux=lista->inicio;pAux!=NULL;pAux=pAux->prox)
			fprintf(stream," %d  %s  %s  %s\n",pAux->info.cod,pAux->info.data,pAux->info.produto,pAux->info.endereco);
			fclose(stream);
			printf("\nGravacao realizada com sucesso!\n");
	}
}

void lerarquivo(ListaEntregas *lista){
	FILE *stream; char entregas[100];Dado d;
	strcpy(entregas,"entregas.txt");
	if((stream = fopen(entregas,"r"))==NULL)
		printf("\nNao foi possivel abrir %s\n",entregas);
	else{
		crialista(lista);
		while(fscanf(stream,"%d %s %s %s\n",&d.cod, &d.data, &d.produto, &d.endereco) != EOF)
			insereentrega(lista,d);
		fclose(stream);
		printf("\nImportacao realizada com sucesso!\n");
	}	
}


