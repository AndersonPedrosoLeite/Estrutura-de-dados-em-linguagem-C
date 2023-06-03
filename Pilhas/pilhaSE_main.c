#include <stdio.h>
#include <stdlib.h>
#include "PilhaSE.h"


int main() {
	
	int op,cod,peso;
	PilhaSE plh;
	Dado d;
	
	
	
	criaPilha(&plh);
	printf("\nDeseja ler um arquivo gravado anteriormente? 1.SIM 2.NAO\n");
	scanf("%d",&op);
	if(op==1){
		lerArquivo(&plh);
		exibe(plh);
	}
	do{
		printf("\n==Escolha a operacao desejada==\n");
		printf("\n1.Empilha\n");
		printf("2.Desempilha\n");
		printf("3.Quantidade de nodos\n");
		printf("4.Exibe situacao da lista\n");
		printf("5.Consulta o topo\n");
		printf("0.Fim\n");
		printf("Escolha a operacao: \n");
		scanf("%d", &op);
		
		switch(op){
			case 1: 
				printf("Insira o codigo e o peso:\n");
				scanf("%d %f",&d.cod,&d.peso);
				if(empilha(&plh,d)==0)
					printf("\nOpercao realizada com sucesso\n");
				else
					printf("\nOperacao nao realizada: Faltou memoria\n");
			break;
			case 2:
				if(desempilha(&plh,&d)==0)
					printf("\nO nodo excluido foi codigo %d peso %.2f\n",d.cod,d.peso);
				else
					printf("\nERRO : A lista esta vazia.\n");
			break;
			case 3:
				printf("\nA quantidade de nodos e %d\n",(quantidadeDeNodos(&plh)));
			break;
			case 4:
				if(situacaodapilha(plh)==SUCESSO)
					printf("\nA pilha pussui um ou mais nodos\n");
				else
					printf("\nA pilha esta vazia\n");
				break;
			case 5:
				if(consultaTopo(plh,&d)==0)
					printf("\nO nodo que esta no topo da lista tem codigo %d peso %.2f.\n",d.cod,d.peso);
				else
					printf("\nERRO : A lista esta vazia.\n");
		}
		exibe(plh);
	}while(op!=0);
	
	printf("\nDeseja salvar o arquivo? 1.SIM 2.NAO\n");
	scanf("%d",&op);
	if(op==1){
		gravaArquivo(&plh);
	}
	
	
	
	
	return 0;
}
