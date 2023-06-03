#ifndef ListaDE_H
#define ListaDE_H

#define SUCESSO 0
#define LISTA_VAZIA 1
#define FALTOU_MEMORIA 2
#define CODIGO_INEXISTENTE 3

typedef struct {
        int cod;
        float peso;
} Dado;
        
typedef struct nodo Nodo;

struct nodo {
       Dado info;
       Nodo *ant;
       Nodo *prox;
};

typedef struct {
        Nodo *inicio;
        Nodo *fim;
        int n;
} ListaDE;

void criaLista(ListaDE *lista);
int incluiNoInicio(ListaDE *lista, Dado d);
void exibe(ListaDE lista);
int quantidadedenodos(ListaDE lista);
int situacaodalista(ListaDE lista);
int excluidoinicio(ListaDE *lista, Dado *d);
int incluinofim(ListaDE *lista,Dado d);
int excluidofim(ListaDE *lista, Dado *d);
int consultaporcodigo(ListaDE lista,int cod, Dado *d);
int incluidepois(ListaDE *lista,int cod, Dado d);
int excluinodo(ListaDE *lista, int cod, Dado *d);
int incluiantes(ListaDE *lista,int cod, Dado d);
void lerarquivo(ListaDE *lista);
void gravaarquivo(ListaDE *lista);
#endif
