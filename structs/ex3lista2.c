#include <stdlib.h>
#include <stdio.h>
#include <locale.h>


struct conta {
	int numero,poupanca,corrente,valor,saldopoupanca,saldocorrente;
};

int depositaNaConta(int *x,int *y);

int retiraDaContaCorrente(int *x, int *y, int *z);

int retiraDaContaPoupanca(int *x,int *y,int *z );

int main ()
{
	setlocale(LC_ALL,"Portuguese");
	struct conta n;
	int operacao,valor;
	printf("Digite o n�mero da sua conta:\n");
	scanf("%d",&n.numero);
	printf("Digite o saldo da conta corrente:\n");
	scanf("%d",&n.corrente);
	n.saldocorrente=n.corrente;
	printf("Digite o saldo da conta poupan�a:\n");
	scanf("%d",&n.poupanca);
	n.saldopoupanca=n.poupanca;
	do{
		printf("\nEscolha a opera��o que deseja realizar:\n");
		printf("1.Dep�sito conta corrente 2.Dep�sito poupan�a 3.Retirada conta corrente 4.Retirada poupan�a 5.Fim\n");
		scanf("%d",&operacao);
		if(operacao<5){
		printf("Qual o valor a ser movimentado:\n");
		scanf("%d",&n.valor);
		
			switch(operacao){
				case 1:{
					printf("Dep�sito na conta corrente.\n");
					depositaNaConta(&n.saldocorrente,&n.valor);
					break;
				}
			
				case 2:{
					printf("Dep�sito na conta poupan�a.\n");
					depositaNaConta(&n.saldopoupanca,&n.valor);
					break;
				}
				case 3:{
					printf("Saque na conta corrente.\n");
					retiraDaContaCorrente(&n.saldocorrente,&n.saldopoupanca,&n.valor);
					break;
				}
				case 4 :{
					printf("Saque na conta poupan�a.\n");
					retiraDaContaPoupanca(&n.saldocorrente,&n.saldopoupanca,&n.valor);
					break;
				}
			}
		}
				printf("\nO saldo da sua conta corrente � R$%d\n",n.saldocorrente);
				printf("\nO saldo da sua conta poupanca � R$%d\n",n.saldopoupanca);
	}while(operacao!=5);
		

	
}

int depositaNaConta(int *x, int *y){
		*x=*x+*y;
}
int retiraDaContaCorrente(int *x, int *y, int *z){
		if(*x>*z || *x==*z){
			*x=*x-*z;
			return -1;
		}
		if(*x<*z && *y>=*z-*x){
			*y=*y-(*z-*x);
			*x=*x-*x;
			return -1;
		}
		if(*y<*z){
			printf("\n>>>Saldo Insuficiente<<<\n");
				return -1;
		}
}
int retiraDaContaPoupanca(int *x,int *y,int *z){
	if(*y>*z || *y==*z){
			*y=*y-*z;
			return -1;
	}
	if(*y<*z){
		printf("\n>>>Saldo Insuficiente!<<<\n");
		return -1;
		
	}
	
}
