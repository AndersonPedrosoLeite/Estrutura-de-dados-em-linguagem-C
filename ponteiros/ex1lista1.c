#include <stdlib.h>
#include <stdio.h>



main(){
	
	int q,i,genero,aluno,alunas=0;
	float altura,aux=0,maisalto,alt,soma,media;
	printf("Qual a quantidade de alunos na turma?\n");
	scanf("%d",&q);
	
	for(i=1;i<=q;i++){
		printf("Qual o genero do aluno?1.Masculino 2.Feminino\n");
		scanf("%d",&genero);	
			if(genero==1){
				printf("Digite a altura do aluno:\n");
					scanf("%f",&altura);
						aux=altura;
						if(aux>maisalto)
							maisalto=aux;
			}
			if(genero==2){
				printf("Digite a altura da aluna:\n");
					scanf("%f",&alt);
						soma=soma+alt;
						alunas++;
			}
	}
	printf("\nO aluno mais alto tem %.2f metros",maisalto);
	media=soma/alunas;
	printf("\nA media da altura das alunas e %.2f metros",media);
	 
	
}
