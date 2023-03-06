#include <stdio.h>
#include <stdlib.h>

typedef struct bloco {
      int dado;
      struct bloco *prox;
} lista, bloco;

int listaVazia (lista *l);
void criarLista (lista **l);
void destruirLista (lista **l);
void inserirInicio (lista **l, int d);
void inserirFinal (lista **l, int d);
void inserirPosK (lista **l, int p, int d);
int removerInicio (lista **l);
int removerFinal (lista **l);
int removerPosK (lista **l, int p);
void inserirOrdenado(lista **l, int d);
void imprimirLista (lista *l);
