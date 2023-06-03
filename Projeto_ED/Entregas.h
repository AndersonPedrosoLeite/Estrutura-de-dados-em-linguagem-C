#ifndef Entregas_H
#define Entregas_H

#define SUCESSO 0
#define LISTA_VAZIA 1
#define FALTOU_MEMORIA 2
#define CODIGO_INEXISTENTE 3

typedef struct {
	int cod;
	char data[100];
	char endereco[100];
	char produto[100];
}Dado;

typedef struct nodo Nodo;

struct nodo {
       Dado info;
       Nodo *ant;
       Nodo *prox;
};

typedef struct {
        Nodo *inicio;
        Nodo *fim;
        int numerodeentregas;
} ListaEntregas;

void criaLista(ListaEntregas *lista);
int insereentrega(ListaEntregas *lista, Dado d);
int fretepago(ListaEntregas *lista, int cod, Dado d);
int fretegratis(ListaEntregas *lista, Dado d);
void listadeentregas(ListaEntregas lista);
int cancelaentrega(ListaEntregas *lista, int cod, Dado *d);
int incluiNoInicio(ListaEntregas *lista, Dado d);
int excluidofim(ListaEntregas *lista, Dado *d);
int quantidadeentregas(ListaEntregas lista);
void gravaarquivo(ListaEntregas *lista);
void lerarquivo(ListaEntregas *lista);


#endif
