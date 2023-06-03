#include <stdio.h>
#include <stdlib.h>

int exibedivisores(int x);

main()
{
	int j;
		for(j=1;j<=20;j++){
			printf("%d: ",j);
			printf("%d",exibedivisores(j));
			printf("\n");
		}
		
}
int exibedivisores(int x){
	int i;
	for(i=1;i<x;i++)
		if(x%i==0)
			printf("%d\t",i);
			return i;
						
}


