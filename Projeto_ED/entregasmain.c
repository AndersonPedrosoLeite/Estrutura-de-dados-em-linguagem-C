#include <stdio.h>
#include <stdlib.h>
#include "Entregas.h"


int main() {
	int op,cod,r,frete;
	char data[100];
	char endereco[100];
	char produto[100];
	ListaEntregas lista;
	Dado d;
	printf("\n******************************************************************");
	printf("\n***************Controle de Entregas para E-commerce***************");
	printf("\n******************************************************************\n");
	printf("\n\tDeseja ver a lista de entregas? 1.Sim 2.Para criar nova lista.\n");
	scanf("%d",&r);
	if(r==1){
		lerarquivo(&lista);
		listadeentregas(lista);
	}else{
	crialista(&lista);
	}
	do{
		printf("\n\t0.Fim.\n");
		printf("\t1.Criar nova Lista.\n");
		printf("\t2.Inserir Nova Entrega.\n");
		printf("\t3.Cancela Entrega.\n");
		printf("\t4.Lista de Entregas.\n");
		printf("\t5.Exibir quantidade de entregas a serem feitas.\n");
		printf("\tEscolha a operacao que deseja realizar: ");
		scanf("%d",&op);
		
		switch(op){
         	case 1:
         			printf("\nCodigo do produto: ");
         			scanf("%d", &d.cod);
         			fflush(stdin);
         			printf("\nData da entrega: ");
         			scanf("%100[^\n]s",&d.data);
         			fflush(stdin);
         			printf("\nNome do produto: ");
         			scanf("%100[^\n]s",&d.produto);
         			fflush(stdin);
         			printf("\nEndereco da entrega: ");
            		scanf("%100[^\n]s",&d.endereco);
            		fflush(stdin);
            			if(insereentrega(&lista, d)==0)
                			printf("\nOperacao Realizada com Sucesso!\n");
      					else
            				printf("\nOperacao nao realizada.Codigo inexistente.\n");
        	break;
			case 2:
         		printf("\n\tQual a forma de envio?1.Frete Pago 2.Frete Gratis\n");
        		scanf("%d",&frete);
        		switch(frete){
					
					case 1:
        					printf("[Codigo de Ref][Codigo do Produto][Data de entrega][Produto][Endereco]\n");
            				scanf(" %d %d %10[^\n] %100[^\n] %100[^\n]",&cod, &d.cod,&d.data,&d.produto,&d.endereco);
            				if(fretepago(&lista,cod, d)==0)
                			printf("\nOperaçao Realizada com Sucesso!\n");
      						else
            				printf("\nOperacao não realizada.Codigo inexistente.\n");
        			break;
      				case 2:
      						printf("[Codigo do Produto][Data de entrega][Produto][Endereco]\n");
							scanf("   %d    %10[^\n]s %100[^\n]s %100[^\n]s",&d.cod,&d.data,&d.produto,&d.endereco);
      		   				fretegratis(&lista,d);
        			 break;
        		}
         	break;
         	case 3:
         			printf("\nDigite o codigo da entrega que sera cancelada:\n");
         			scanf("%d",&cod);
         				if(cancelaentrega(&lista,cod,&d)==SUCESSO)
         					printf("\nA entrega excluida foi codigo %d data a ser entregue %s nome do produto %s  endereço %s.\n]",d.cod,d.data,d.produto,d.endereco);
         				else
         					printf("\nERRO: Codigo inexistente\n");
        	break;
         	
         	case 4:
         		listadeentregas(lista);
         	break;
         	case 5:
         		printf("\nA quantidade de entregas a serem realizadas sao  %d.\n",quantidadeentregas(lista));
         	    break;
         	}
		listadeentregas(lista);
	}while(op!=0);
	printf("\n\nDeseja salvar a lista? 1.SIM 2.NAO\n");
        	scanf("%d",&r);
        	if(r==1)
        	gravaarquivo(&lista);
        	listadeentregas(lista);
			
	return 0;
}
