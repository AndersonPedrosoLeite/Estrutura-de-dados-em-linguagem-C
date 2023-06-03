#include <stdio.h>
#include <stdlib.h>
#include "ListaSE.h"

void criaLista(ListaSE *lt){
	lt->inicio = NULL;
}

int incluiNoInicio(ListaSE *lt, Dado d){
	Nodo *pNodo;
	pNodo = (Nodo *) malloc (sizeof (Nodo)); //cria um novo espaço do tamanho de um nodo, pnodo recebe esse novo endereço//
	if(pNodo == NULL)
		return(	FALTOU_MEMORIA);
	else {
	pNodo->info = d;
	pNodo->prox = lt->inicio;
	lt->inicio = pNodo;
	return (SUCESSO);
	}
}

void exibe(ListaSE lt){
     Nodo *pAux;
     pAux = lt.inicio;
     printf("\nInicio: %p \n", lt.inicio);
     printf("Exibindo a Lista\n");
     printf("[EndNodo] [cd] [peso] [EndProx]\n");
     while (pAux != NULL) {
           printf("%p - %3d %.2f - %p\n", pAux, pAux->info.cod, pAux->info.peso, pAux->prox);
           pAux = pAux->prox;
     }
}

int quantidadeDeNodos(ListaSE lt){
	int conta=0;
	Nodo *pAux;
	int c;
	pAux = lt.inicio;
	while(pAux != NULL){
		conta++;
		pAux = pAux->prox;
	}
		return (conta);
}

int situacaoDaLista(ListaSE lt){
	if(lt.inicio==NULL)
		return LISTA_VAZIA;
	else
		return SUCESSO;
}


int excluiDoInicio(ListaSE *lt, Dado *d){
	Nodo *pTemp;
	if (lt->inicio==NULL)
		return LISTA_VAZIA;
	else{
		*d = lt->inicio->info;             // exclui o primeiro nodo e guarda as informações no endereço apontado por *d//
		pTemp= lt->inicio ;               // pTemp guarda o endereço do nodo início//
		lt->inicio=lt->inicio->prox;       // preserva o endereço do próximo nodo//
		free (pTemp);
		return SUCESSO;
	}
}


int incluiNoFim(ListaSE *lt, Dado d){
		Nodo *pNodo,*pAux;
	pNodo = (Nodo *) malloc (sizeof (Nodo)); //cria um novo espaço do tamanho de um nodo, pnodo recebe esse novo endereço//
	if(pNodo == NULL)
		return(	FALTOU_MEMORIA);
	else if(lt->inicio==NULL){
		pNodo->info=d;
		lt->inicio=pNodo;
		lt->inicio->prox=NULL;
		return SUCESSO;
	}else{
		pAux = lt->inicio;
	while(pAux->prox!=NULL){
		pAux = pAux->prox;
		}
		pNodo->info=d;
		pNodo->prox=NULL;
		pAux->prox=pNodo;
		return SUCESSO;
	}
}								//Quando a lista está vazia o inicio deve receber o endereço do novo nodo.
												
int excluiDoFim(ListaSE *lt,Dado *d){
	Nodo *pAux,*pTemp;
	if(lt->inicio==NULL){
		return LISTA_VAZIA;
	}
	else if(lt->inicio->prox==NULL){
		*d=lt->inicio->info;
		pTemp=lt->inicio;
		free(pTemp);
		lt->inicio=NULL;
		return SUCESSO;
	}
	else{
		pAux = lt->inicio;
		while(pAux->prox->prox!=NULL){
			pAux = pAux->prox;                   //Ele vai parar no penultimo nodo da Lista
		}
		*d=pAux->prox->info;				//Se ele parou no penultimo, aqui ele Vai enviar informações do ultimo nodo
		pTemp=pAux->prox;
		pAux->prox=NULL;
		free(pTemp);
		return SUCESSO;	
	}
}	

int consultaPorCodigo(ListaSE lt,int cod,Dado *d ){
		 Nodo *pAux;
     pAux = lt.inicio;
    while(pAux!=NULL){
    	if(pAux->info.cod==cod){
    		*d=pAux->info;
			return SUCESSO;
		}
    	pAux=pAux->prox;
    }
    	return CODIGO_INEXISTENTE;
}											//quando a lista contem nodos ,prox do último deve receber o endereçodo novo nodo
												
												//Para encontrar o enderço do ultimo interronper a repetição quando pAux->pro}

int incluiDepois(ListaSE *lt,int cod,Dado d){
		Nodo *pNodo,*pAux;
	pNodo = (Nodo *) malloc (sizeof (Nodo)); 
	if(pNodo == NULL)
		return(FALTOU_MEMORIA);
	else {
		pAux = lt->inicio;
		while(pAux != NULL){
			if(pAux->info.cod==cod){
				pNodo->info = d;
				pNodo->prox = pAux->prox;		//	pNodo->info.cod=d.cod; pNodo->info.peso=d.peso
				pAux->prox=pNodo;
				return SUCESSO;
			}
			pAux = pAux->prox;
		}
		return CODIGO_INEXISTENTE;
	}
}

void lerArquivo(ListaSE *lt){
	FILE *stream; char listase[10];Dado d;
	strcpy(listase,"listase.txt");
	if((stream = fopen(listase,"r"))==NULL)
		printf("\nNao foi possivel abrir %s\n",listase);
	else{
		criaLista(lt);
		while (fscanf(stream," %d %f\n", &d.cod, &d.peso) != EOF)
			incluiNoFim(lt,d);
		fclose(stream);
		printf("\nImportacao Realizada com Sucesso!\n");
	}
}

void gravaArquivo(ListaSE *lt){
	FILE *stream;
	char listase[10];
		int i,n;
	Nodo *pAux;
	
	
	strcpy(listase,"listase.txt");
	
	if((stream =fopen(listase,"w"))==NULL)
		printf("Nao foi possivel abrir %s\n",listase);
		
	else{
			for(pAux=lt->inicio;pAux!=NULL;pAux=pAux->prox)
			fprintf(stream,"%d %.2f\n",pAux->info.cod,pAux->info.peso);
		fclose(stream);
		printf("Gravacao realizada com sucesso!\n");
	
	}
}
















