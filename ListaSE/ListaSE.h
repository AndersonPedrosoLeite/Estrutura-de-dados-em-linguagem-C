#ifndef ListaSE_H
#define ListaSE_H

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
       Nodo *prox;
};

typedef struct {
        Nodo *inicio; // aponta para o primeiro endereço da lista
} ListaSE;


void criaLista(ListaSE *lt);
int incluiNoInicio(ListaSE *lt, Dado d);
void exibe(ListaSE lt);
int quantidadeDeNodos(ListaSE lt);
int situacaoDaLista(ListaSE lt);
int excluiDoInicio(ListaSE *lt, Dado *d);
int incluiNofim(ListaSE *lt, Dado d);
int excluiDoFim(ListaSE *lt,Dado *d);
int consultaPorCodigo(ListaSE lt,int cod,Dado *d );
int incluiDepois(ListaSE *lt,int cod,Dado d);
void lerArquivo(ListaSE *lt);
void gravaArquivo(ListaSE *lt);
#endif
