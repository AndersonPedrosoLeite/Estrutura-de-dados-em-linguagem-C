#include <stdlib.h>
#include <stdio.h>

main(){
	int q,i,z[10],w[10],y,c=0;
	printf("Digite um valor que sera o tamanho do vetor: \n");
	scanf("%d",&q);
		for(i=0;i<=q;i++){
			printf("Digite o valor do elemento %d:\n",i);
			scanf("%d",&z[i]);
		}
		printf("\n");
		for(i=0;i<=q;i++){
			printf("\t%d",z[i]);
		}
		printf("\nDigite um valor:\n");
		scanf("%d",&y);
		
		for(i=0;i<=q;i++){
			if(z[i]>y){
			w[c]=z[i];	
				c++;
			}
		}
		printf("\n");
		for(i=0;i<=c-1;i++){
			printf("\t%d",w[i]);
		}
}

