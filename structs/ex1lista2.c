#include <stdio.h>
#include <stdlib.h>

struct Hora {
	int hora ,min ,seg ;
};

int main ()
{
	struct Hora hr1,hr2;
	printf("Informe os horarios pressionando a tecla espaco entre hora minuto e segundo.\n");
	printf("Informe o primeiro horario:\n");
	scanf("%d %d %d",&hr1.hora,&hr1.min,&hr1.seg);
	printf("Informe o segundo horario:\n");
	scanf("%d %d %d",&hr2.hora,&hr2.min,&hr2.seg);
	
	if(hr1.hora==hr2.hora){
		printf("Horarios iguais");
	}
	if(hr1.hora>hr2.hora){
		printf("O menor horário e %d horas %d minutos %d segundos",hr2.hora,hr2.min,hr2.seg);
	}
	if(hr1.hora<hr2.hora){
		printf("O menor horario e %d horas %d minutos %d segundos",hr1.hora,hr1.min,hr1.seg);
	}
} 
