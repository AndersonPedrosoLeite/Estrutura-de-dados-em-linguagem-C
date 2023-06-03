#include <stdlib.h>
#include <stdio.h>

int maiornumero(int x, int y);

main()
{
	int n1,n2,resultado;
	printf("Digite o primeiro numero:\n");
	scanf("%d",&n1);
	printf("Digite o segundo numero:\n");
	scanf("%d",&n2);
	maiornumero(n1,n2);
	resultado=maiornumero(n1,n2);
	printf("\n%d",resultado);
}

int maiornumero(int x,int y){
	int aux;
		if(x>y){
			aux=x;
				return aux;
		}
		if(x<y){
			aux=y;
				return aux;
		}
		if(x==y){
			printf("Eles sao iguais");
			return -1;
		}
}
