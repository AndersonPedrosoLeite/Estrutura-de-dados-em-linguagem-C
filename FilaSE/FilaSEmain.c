#include <stdio.h>
#include <stdlib.h>
#include "FilaSE.h"



int main() {
	
	int op,cod,peso;
	Dado d;
	FilaSE fl;
	
	criaFila(&fl);
	printf("\nDeseja ler um arquivo gravado anteriormente? 1.SIM 2.NAO\n");
	scanf("%d",&op);
	if(op==1){
		lerArquivo(&fl);
		exibefila(fl);
	}
	do{
	printf("\n===Digite a operacao que deseja realizar===\n");
	printf("\n0.Fim\n");
	printf("1.Insere\n");
	printf("2.Retira\n");
	printf("3.Quantidade de modos\n");
	printf("4.Exibe situacao da fila\n");
	printf("5.Consulta frente\n");
	scanf("%d",&op);
	
		switch(op){
			case 1:
				printf("Insira o codigo e o peso:\n");
				scanf("%d %f",&d.cod,&d.peso);
				if(insere(&fl,d)==0)
					printf("\n***Dados inseridos com sucesso***\n");
				else
					printf("\n***ERRO:Faltou memoria***\n");
				break;
			case 2:
				if(retira(&fl,&d)==0)
					printf("\n=>O nodo excluido foi codigo %d peso %.2f\n",d.cod,d.peso);
				else
					printf("\n***ERRO : Fila vazia!***\n");
				break;
			case 3:
					printf("\n-A quantidade de nodos e %d.\n",(quantidadedeNodos(&fl)));
				break;
			case 4:
				if(situacaodaFila(fl)==SUCESSO)
					printf("\nA fila possui um ou mais nodos.\n");
				else
					printf("\n!!!A fila esta vazia!!!\n");
				break;
			case 5:
				if(consultaFrente(fl,&d)==SUCESSO)
					printf("\nO primeiro nodo da fila tem codigo %d e peso %.2f.\n",d.cod,d.peso);
				else
					printf("\nERRO : A lista esta vazia\n");
				break;	
				
		}
		exibefila(fl);
	}while(op!=0);
		
		printf("\nDeseja salvar o arquivo? 1.Sim 2.NAO\n");
		scanf("%d",&op);
			if(op==1){
				gravaArquivo(&fl);
			}
		return 0;
}









