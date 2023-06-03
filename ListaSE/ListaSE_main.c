#include <stdio.h>
#include <stdlib.h>
#include "ListaSE.h"


int main() {
	int op,cd,peso,r;
	ListaSE lt;
	Dado d;

	printf("Deseja ler um arquivo gravado anteriormente? 1.Sim 2.Nao\n");
	scanf("%d",&r);
	if(r==1){
		lerArquivo(&lt);
		exibe(lt);
	}else{
		criaLista(&lt);
	}
	
	
		
    do {
      printf("\n0. Fim                         5. Exclui do Inicio         10. Exclui Nodo\n");    
      printf("1. Inclui no Inicio            6. Inclui no Fim            \n");    
      printf("2. Exibe Lista                 7. Exclui do Fim            \n");    
      printf("3. Quantidade de Nodos         8. Consulta por Codigo      \n");    
      printf("4. Exibe Situacao da Lista     9. Inclui Depois.           \n");
      printf("Operacao: ");    
      scanf("%d", &op);
      
      switch(op){
      	case 1:
      		printf("[cd][peso]\n");
            scanf (" %d %f", &d.cod,&d.peso);
            if (incluiNoInicio(&lt, d)==0)
                printf("Operacao Realizada com Sucesso!\n");
            else
            	 printf("Operacao NAO realizada: Faltou Memoria!");
            break;
	  
      	case 2: 
		  	exibe(lt);
      		break;
      	case 3: 
		  	printf("A quantidade de nodos e %d",quantidadeDeNodos(lt));
			break;
      	case 4:
      		if(situacaoDaLista(lt)==LISTA_VAZIA)
      			printf("A lista esta vazia!\n");
      		else
      			printf("A lista contem um ou mais nodos\n");
      		break;
		case 5: 
			excluiDoInicio(&lt,&d);
			printf("O nodo excluido foi %d %.2f",d.cod,d.peso);
      		break;
      	case 6:printf("Digite o codigo e o peso que serao incluidos:\n");
      		   scanf("%d %f",&d.cod,&d.peso);
      		   incluiNoFim(&lt,d);
      		   break;
      	case 7:
      		if(excluiDoFim(&lt,&d)==LISTA_VAZIA)
      			printf("A lista esta vazia.\n");
      		else
      			printf("%d %.2f",d.cod,d.peso);
      		   break;
      	case 8:
      		printf("Digite o codigo que esta buscando");
      		scanf("%d",&cd);
      		if(consultaPorCodigo(lt,cd,&d )==0);
      			printf("%d %.2f",d.cod,d.peso);
      		break;
      	
      	case 9:	
		  	printf("[cod Ref][cd][peso]\n");
            scanf (" %d %d %f",&cd, &d.cod,&d.peso);
            if (incluiDepois(&lt,cd, d)==0)
                printf("Operacao Realizada com Sucesso!\n");
            else
            	printf("Operacao nao realizada.Codigo inexistente.\n");
        	break;
     
      }
        	
      	exibe(lt);
	
	
	}while (op!=0);
      	    printf("\n\nDeseja salvar a lista? 1.SIM 2.NAO\n");
        	scanf("%d",&r);
        	if(r==1)
        	gravaArquivo(&lt);
			exibe(lt);
	return 0;
}
