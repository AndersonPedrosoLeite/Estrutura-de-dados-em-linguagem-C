#ifndef PilhaSE_H
#define PilhaSE_H

#define SUCESSO 0
#define PILHA_VAZIA 1
#define FALTOU_MEMORIA 2

typedef struct {
	int cod ;
	float peso ;
}Dado;


typedef struct nodo Nodo;

struct nodo {
	Dado info ;
	Nodo *prox ;
};

typedef struct{
	Nodo *topo;    //campo Nodo tipo PilhaSE//
} PilhaSE;

void criaPilha(PilhaSE *p);
int empilha(PilhaSE *p, Dado d);
int desempilha(PilhaSE *p, Dado *d);
int quantidadeDeNodos(PilhaSE *p);
int situacaodapilha(PilhaSE p);
void exibe(PilhaSE p);
int consultaTopo(PilhaSE p, Dado *d);
#endif
