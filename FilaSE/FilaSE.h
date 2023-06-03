#ifndef FilaSE_H
#define FilaSe_H

#define SUCESSO 0
#define FILA_VAZIA 1
#define FALTOU_MEMORIA 2


typedef struct {
	int cod;
	float peso;
}Dado;

typedef struct nodo Nodo;

struct nodo {
	Dado info;
	Nodo *prox;
};

typedef struct {
	Nodo *frente;
	Nodo *re;
}FilaSE;

void criaFila(FilaSE *fila);
int insere(FilaSE *fila,Dado d);
int retira(FilaSE *fila,Dado *d);
void exibefila(FilaSE fila);
int quantidadedeNodos(FilaSE *fila);
int situacaodaFila(FilaSE fila);
int consultaFrente(FilaSE fila, Dado *d);
void lerArquivo(FilaSE *fila);
void gravaArquivo(FilaSE *fila);
#endif
