#include <stdlib.h>
#include <stdio.h>
#include "PilhaSE.h"

void criaPilha(PilhaSE *p){
	p->topo=NULL;
}
int empilha(PilhaSE *p, Dado d){
	Nodo *topo,*pNodo;
	pNodo = (Nodo *) malloc (sizeof(Nodo));
	if(pNodo == NULL)
		return FALTOU_MEMORIA;
	else{
		pNodo->info = d;
		pNodo->prox = p->topo;   
		p->topo = pNodo;   //o topo da pilha recebe o novo nodo//
		return SUCESSO;
	}
}

int desempilha(PilhaSE *p, Dado *d){
	Nodo *pTemp;
	if(p->topo == NULL)
		return PILHA_VAZIA;
	else{
		*d = p->topo->info;
		pTemp = p->topo;
		p->topo=p->topo->prox; //o topo da pilha recebe o proximo nodo//
		free(pTemp);
		return SUCESSO;
	}
}

int consultaTopo(PilhaSE p, Dado *d){
		Nodo *pAux;
		pAux = p.topo;
	if(pAux == NULL)
		return PILHA_VAZIA;
	else{
		*d = pAux->info;
		return SUCESSO;
	}
}

int quantidadeDeNodos(PilhaSE *p){
	Nodo *pAux;
	int c=0;
	pAux = p->topo;
		while(pAux!=NULL){
		c++;
		pAux=pAux->prox;
		}
		return c;
}


int situacaodapilha(PilhaSE p){

	if(p.topo== NULL){
		return PILHA_VAZIA;
	}else{
		return SUCESSO;
	}
	
}

void exibe(PilhaSE p){
	Nodo *pAux;
	pAux = p.topo;
	printf("\nInicio: %p \n",p.topo);
	printf("Exibindo a lista:\n");
	printf("[EndNodo]  [cd]  [peso]  [EndProx]\n");
	while(pAux != NULL){
		printf("%p - %d %.2f - %p\n",pAux,pAux->info.cod,pAux->info.peso,pAux->prox);
		pAux = pAux->prox;
	}
} 



//quando o campo prox apontar para NUll terminaram os elementos da pilha//






//consulta lê só o que está no topo
void lerArquivo(PilhaSE *p){
	FILE *stream; char pilhase[20];Dado d;
	strcpy(pilhase,"pilhase.txt");
	if((stream = fopen(pilhase,"r"))==NULL)
		printf("\nNao foi possivel abrir %s\n",pilhase);
	else{
		while (fscanf(stream," %d %f\n", &d.cod, &d.peso) != EOF)
			empilha(p,d);
		fclose(stream);
		printf("\nImportacao Realizada com Sucesso!\n");
	}
}

void gravaArquivo(PilhaSE *p){
	FILE *stream;
	char pilhase[20];
		int i,n;
	Nodo *pAux;
	
	
	strcpy(pilhase,"pilhase.txt");
	
	if((stream =fopen(pilhase,"w"))==NULL)
		printf("Nao foi possivel abrir %s\n",pilhase);
		
	else{
			for(pAux=p->topo;pAux!=NULL;pAux=pAux->prox)
			fprintf(stream,"%d %.2f\n",pAux->info.cod,pAux->info.peso);
		fclose(stream);
		printf("Gravacao realizada com sucesso!\n");
	
	}
}

