#include <stdio.h>
#include <stdlib.h>
struct Data{
	int dia,mes,ano;
};
struct Aluno{
	int matricula;
	struct Data dtaNasc,dthoje;
};

int main ()
{
	int idade;
	struct  Aluno func;
	
	do{
	printf("\nInforme o numero da matricula:\n");
	scanf("%d",&func.matricula);
	if(func.matricula<0){
		break;
	}
	printf("Informe a data de hoje incluindo espacos entre dia mes e ano:\n");
	scanf("%d %d %d",&func.dthoje.dia,&func.dthoje.mes,&func.dthoje.ano);
	printf("Informe o dia de nascimento do aluno:\n");
	scanf("%d",&func.dtaNasc.dia);
	printf("Informe um numero de 1 a 12 referente ao mes de nascimento:\n");
	scanf("%d",&func.dtaNasc.mes);
	printf("Informe o ano de nascimento do aluno:\n");
	scanf("%d",&func.dtaNasc.ano);
	
	idade=func.dthoje.ano-func.dtaNasc.ano;
		if(idade>=18){
			printf("O aluno(a) ja completou 18 anos e eh maior de idade.\n",idade);
		}
		if(idade<18){
			printf("O aluno(a) ainda nao completou 18 anos e eh menor de idade.\n",idade);
		}
	}while(func.matricula>0);
}
