#include <stdio.h>
#include <stdlib.h>
#include "ListaDE.h"

void crialista(ListaDE *lista){
	lista->inicio = NULL;
	lista->fim = NULL;
	lista->n = 0;
}

int incluinoinicio(ListaDE *lista, Dado d){
	Nodo *pNodo;
	pNodo = (Nodo *) malloc (sizeof (Nodo));
	if(pNodo == NULL)
		return(FALTOU_MEMORIA);
	else{
		pNodo->info = d;
		pNodo->prox = lista->inicio;
		pNodo->ant = NULL;
		
		if(lista->n == 0)
			lista->fim = pNodo;
		else
			lista->inicio->ant = pNodo;	
			
		lista->inicio = pNodo;
		lista->n++;
		return SUCESSO;
	}
}

void exibe(ListaDE lista){
     Nodo *pAux;
     pAux = lista.inicio;
     printf("\nExibindo a Lista\n");
     printf("Inicio: %p \n", lista.inicio);
     printf("[End Ant] [cd] [End Nodo] [peso] [End Prox]\n");
     while (pAux != NULL) {
           printf("%p - %3d %p %.2f - %p\n", pAux->ant, pAux->info.cod, pAux, pAux->info.peso, pAux->prox);
           pAux = pAux->prox;
     }
     printf("Fim: %p - N= %d\n", lista.fim, lista.n);
}

int quantidadedenodos(ListaDE lista){
	int c = 0;
	Nodo *pAux;
	pAux = lista.inicio;
	while(pAux!=NULL){
		c++;
		pAux = pAux->prox	;
	}
		return c;
}

int situacaodalista(ListaDE lista){
	if(lista.inicio==NULL)
		return LISTA_VAZIA;
	else
		return SUCESSO;
}
int excluidoinicio(ListaDE *lista, Dado *d){
	Nodo *pNodo;
	if(lista->n==0)
		return LISTA_VAZIA;
	else{
		*d = lista->inicio->info;
		pNodo = lista->inicio;
		lista->inicio = lista->inicio->prox;
		if(lista->n==1)
			lista->fim = NULL;
		else
			lista->inicio->ant = NULL;
		lista->n--;
		free (pNodo);
		return SUCESSO;
	}	
} 

int incluinofim(ListaDE *lista,Dado d){
		Nodo *pNodo,*pAux;
	pNodo = (Nodo *) malloc (sizeof (Nodo));
	if(pNodo == NULL)
		return FALTOU_MEMORIA;
	else if(lista->n == 0){
		pNodo->info = d;
		pNodo->ant = NULL;
		pNodo->prox=NULL;
		lista->inicio=pNodo;
		lista->fim=pNodo;
		lista->n++;
		return SUCESSO;
	}
	else{
		pNodo->info = d;
		pNodo->prox=NULL;
		lista->fim->prox = pNodo;
		pNodo->ant = lista->fim;
		lista->fim = pNodo;
		lista->n++;
		return SUCESSO;
	}	
}

int excluidofim(ListaDE *lista, Dado *d){
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
		lista->n--;
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
		lista->n--;
		return SUCESSO;
	}
}

int consultaporcodigo(ListaDE lista,int cod, Dado *d){
	Nodo *pAux;
	pAux = lista.inicio;
	while(pAux!=NULL){
		if(pAux->info.cod==cod){
			*d=pAux->info;
			return SUCESSO;
		}
		pAux=pAux->prox;
	}
	return CODIGO_INEXISTENTE;
}

int incluidepois(ListaDE *lista,int cod, Dado d){
	Nodo *pNodo, *pAux;
	pNodo = (Nodo *) malloc (sizeof (Nodo)); 
	if(pNodo == NULL)
		return(FALTOU_MEMORIA);
	else{
		pAux = lista->inicio;
		while(pAux != NULL){
			if(pAux->info.cod==cod){
				pNodo->info = d;
				if(pAux==lista->fim){
					pNodo->prox = NULL;
					lista->fim->prox = pNodo;
					pNodo->ant = lista->fim;
					lista->fim = pNodo;
				}
				else{
					pNodo->ant = pAux;
					pNodo->prox = pAux->prox;
					pAux->prox = pNodo;
					pNodo->prox->ant = pNodo;
				}
				lista->n++;
				return SUCESSO;
			}
			pAux = pAux->prox;
		}
		return CODIGO_INEXISTENTE;
	}
}

int incluiantes(ListaDE *lista,int cod, Dado d){
	Nodo *pNodo, *pAux;
	pNodo = (Nodo *) malloc (sizeof (Nodo)); 
	if(pNodo == NULL)
		return(FALTOU_MEMORIA);
	else{
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
				lista->n++;
				return SUCESSO;
			}
			pAux = pAux->ant;
		}
		return CODIGO_INEXISTENTE;
	}
}
int excluinodo(ListaDE *lista, int cod, Dado *d){  
	Nodo *pAux, *pTemp, *pAux2;     
	
		pAux = lista->inicio;
		while(pAux!=NULL){
			if(pAux->info.cod==cod){
				*d =pAux->info;
				pTemp= pAux;
				if(lista->n==1){
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
				lista->n--;
				return SUCESSO;
			}
			pAux=pAux->prox;
		}
		return CODIGO_INEXISTENTE;
}


void lerarquivo(ListaDE *lista){
	FILE *stream; char listade[20];Dado d;
	strcpy(listade,"listade.txt");
	if((stream = fopen(listade,"r"))==NULL)
		printf("\nNao foi possivel abrir %s\n",listade);
	else{
		crialista(lista);
		while(fscanf(stream," %d %f\n",&d.cod, &d.peso) != EOF)
			incluinoinicio(lista,d);
		fclose(stream);
		printf("\nImportacao realizada com sucesso!\n");
	}
}

void gravaarquivo(ListaDE *lista){
	FILE *stream;
	char listade[20];
		int i,n;
	Nodo *pAux;
	
	strcpy(listade,"listade.txt");
	if((stream=fopen(listade,"w"))==NULL)
		printf("\nNao foi possivel abrir %s\n",listade);
	else{
			for(pAux=lista->inicio;pAux!=NULL;pAux=pAux->prox)
			fprintf(stream,"%d %.2f\n",pAux->info.cod,pAux->info.peso);
			fclose(stream);
			printf("\nGravacao realizada com sucesso!\n");
	}
}
	
	





















