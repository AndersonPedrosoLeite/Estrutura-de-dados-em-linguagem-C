#include <stdio.h>
#include <stdlib.h>
#include "ListaDE.h"

int main(){
	int op,cod,peso,r;
	ListaDE lista;
	Dado d;
	
	printf("Deseja ler um arquivo gravado anteriormente? 1.Sim 2.Nao\n");
	scanf("%d",&r);
	if(r==1){
		lerarquivo(&lista);
		exibe(lista);
	}else{
	crialista(&lista);
	}
	
	do{
		printf("\n0. Fim                         5. Exclui do Inicio         10. Exclui Nodo	\n");    
      printf("1. Inclui no Inicio            6. Inclui no Fim            11.Inclui antes \n");    
      printf("2. Exibe Lista                 7. Exclui do Fim            \n");    
      printf("3. Quantidade de Nodos         8. Consulta por Codigo     \n");    
      printf("4. Exibe Situacao da Lista     9. Inclui Depois			\n");
      printf("Operacao: ");    
      scanf("%d", &op);
      
      switch(op){
      	 case 1:
                printf("[cd][peso]\n");
                scanf (" %d %f", &d.cod,&d.peso);
                if (incluinoinicio(&lista, d)==0)
                    printf("Operacao Realizada com Sucesso!\n");
                else
                 	printf("Operacao NAO realizada: Faltou Memoria!");
         break;
         case 2:
         		exibe(lista);
         		break;
         case 3:
         		printf("\nA quantidade de nodos e %d.\n",quantidadedenodos(lista));
         	    break;
         case 4:
         		if(situacaodalista(lista)==1)
         			printf("\nA lista esta vazia.\n");
				else
				 	printf("\nA lista contem um ou mais nodos.\n");
				
				break;
         case 5:
         		if(excluidoinicio(&lista, &d)==LISTA_VAZIA)
         			printf("\nA Lista esta Vazia\n");
         		else
         			printf("\nO nodo excluido foi %d %.2f\n",d.cod,d.peso);
         		break;
         		
		 case 6 :printf("\nDigite o codigo e o peso que serao incluidos:\n");
      		   scanf("%d %f",&d.cod,&d.peso);
      		   incluinofim(&lista,d);
      	 break;
      	 case 7 :
      	 		if(excluidofim(&lista,&d)==LISTA_VAZIA)
      			printf("\nA lista esta vazia.\n");
      			else
      			printf("\nO nodo excluido foi o de codigo %d e peso %.2f.\n",d.cod,d.peso);
      	 break;
      	 
      	 case 8 :
      	 	printf("\nDigite o codigo que esta buscando:\n");
      		scanf("%d",&cod);
      		if(consultaporcodigo(lista,cod,&d)==0)
      			printf("\nO nodo de codigo %d possui peso %.2f.\n",d.cod,d.peso);
      		else
      			printf("\nERR0: Codigo inexistente\n");
      	 break;
      	
      	 case 9 :
      	 	printf("[cod Ref][cd][peso]\n");
            scanf (" %d %d %f",&cod, &d.cod,&d.peso);
            if (incluidepois(&lista,cod, d)==0)
                printf("\nOperacao Realizada com Sucesso!\n");
            else
            	printf("\nOperacao nao realizada.Codigo inexistente.\n");
         break;
         case 10 :
         	printf("\nDigite o codigo do nodo que sera excluido:\n");
         	scanf("%d",&cod);
         		if(excluinodo(&lista,cod,&d)==SUCESSO)
         			printf("\nO nodo excluido foi de cod %d e peso %.2f.\n",d.cod,d.peso);
         		else
         			printf("\nERRO: Codigo inexistente\n");
        break;
        case 11 :
        		printf("[cod Ref][cd][peso]\n");
            scanf (" %d %d %f",&cod, &d.cod,&d.peso);
            if (incluiantes(&lista,cod, d)==0)
                printf("\nOperacao Realizada com Sucesso!\n");
            else
            	printf("\nOperacao nao realizada.Codigo inexistente.\n");
         break;
        }
      	exibe(lista);
      	
	  }while(op!=0);
	  		printf("\n\nDeseja salvar a lista? 1.SIM 2.NAO\n");
        	scanf("%d",&r);
        	if(r==1)
        	gravaarquivo(&lista);
			exibe(lista);
	  
	  return(0);
}



