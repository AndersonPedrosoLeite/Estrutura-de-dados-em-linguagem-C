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
	printf("Digite o número da sua conta:\n");
	scanf("%d",&n.numero);
	printf("Digite o saldo da conta corrente:\n");
	scanf("%d",&n.corrente);
	n.saldocorrente=n.corrente;
	printf("Digite o saldo da conta poupança:\n");
	scanf("%d",&n.poupanca);
	n.saldopoupanca=n.poupanca;
	do{
		printf("\nEscolha a operação que deseja realizar:\n");
		printf("1.Depósito conta corrente 2.Depósito poupança 3.Retirada conta corrente 4.Retirada poupança 5.Fim\n");
		scanf("%d",&operacao);
		if(operacao<5){
		printf("Qual o valor a ser movimentado:\n");
		scanf("%d",&n.valor);
		
			switch(operacao){
				case 1:{
					printf("Depósito na conta corrente.\n");
					depositaNaConta(&n.saldocorrente,&n.valor);
					break;
				}
			
				case 2:{
					printf("Depósito na conta poupança.\n");
					depositaNaConta(&n.saldopoupanca,&n.valor);
					break;
				}
				case 3:{
					printf("Saque na conta corrente.\n");
					retiraDaContaCorrente(&n.saldocorrente,&n.saldopoupanca,&n.valor);
					break;
				}
				case 4 :{
					printf("Saque na conta poupança.\n");
					retiraDaContaPoupanca(&n.saldocorrente,&n.saldopoupanca,&n.valor);
					break;
				}
			}
		}
				printf("\nO saldo da sua conta corrente é R$%d\n",n.saldocorrente);
				printf("\nO saldo da sua conta poupanca é R$%d\n",n.saldopoupanca);
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
