#include <stdio.h>
#include <stdlib.h>

void duplaclassificada(int *x, int *y);

main()
{	
	int	 a,b,ordem;
	
	do{
		printf("\nInforme o primeiro valor:\n");
		scanf("%d",&a);
		printf("Informe o segundo valor:\n");
		scanf("%d",&b);
		duplaclassificada(&a,&b);
		printf("%d\t%d",a,b);
	}while(a!=b);
	
	
	
}
 void duplaclassificada(int *x, int *y){
	int aux,soma;
		soma=*x+*y;
		if(soma%2==1){
			aux=*y;
			*y=*x;
			*x=aux;
		}
}
