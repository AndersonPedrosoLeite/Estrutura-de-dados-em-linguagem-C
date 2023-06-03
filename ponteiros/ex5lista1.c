#include <stdio.h>
#include <stdlib.h>

int duplacrescente(int *x, int *y);


main(){
		int a,b,ordem;
	do{
		printf("\nDigite o primeiro valor\n");
		scanf("%d",&a);
		printf("Digite o segundo valor\n");
		scanf("%d",&b);
		duplacrescente(&a,&b);
		printf("\n%d\t%d",a,b);
		
	}while(a!=b);
}

int duplacrescente(int *x, int *y){
	int aux;
		if(*x<*y){
			aux=*y;
			*y=*x;
			*x=aux;
		}
		if(*x>*y){
			aux=*x;
			*x=*y;
			*y=aux;
		}
}

