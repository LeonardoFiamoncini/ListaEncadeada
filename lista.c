#include "lista.h"

int listaVazia (lista *l) {

    return (l == NULL);
}

void criarLista (lista **l) {

    *l = NULL;
}

void inserirInicio (lista **l, int d) {

    bloco *b = (bloco *)malloc(sizeof(bloco));

    b->dado = d;
    b->prox = *l;
    *l = b;
}

void inserirFinal (lista **l, int d) {

    bloco *tmp = *l;
    bloco *b = (bloco *)malloc(sizeof(bloco));

    b->dado = d;
    b->prox = NULL;

    while (tmp->prox != NULL)
        tmp = tmp->prox;

    tmp->prox = b;
    
}

void inserirPosK (lista **l, int p, int d) {

    if (!listaVazia(*l)) {
        if (p == 1)
           inserirInicio(l, d);
        else {
           int pos = 1;
           bloco *tmp = *l;
           bloco *ant = NULL;
           bloco *b = (bloco *)malloc(sizeof(bloco));
           b->dado = d;
           b->prox = NULL;

           while (pos < p && tmp != NULL) {
             ant = tmp;
             tmp = tmp->prox;
             pos++;
           }
           ant->prox = b;
           b->prox = tmp;
        }
    }
    else
       inserirInicio(l, d);
}

int removerInicio (lista **l) {
    if (!listaVazia(*l)) {
       int dado = (*l)->dado;

       bloco *tmp = *l;
       *l = (*l)->prox;
       free(tmp);

       return dado;
    }
}

int removerFinal (lista **l) {
    if (!listaVazia(*l)) {
        int dado;

        bloco *tmp = *l;
        bloco *ant = NULL;

        while (tmp->prox != NULL) {
            ant = tmp;
            tmp = tmp->prox;
        }

        ant ->prox = NULL;
        free(tmp);

        return dado;
    }
}

int removerPosK (lista **l, int p) {

    if (!listaVazia(*l)) {
        int dado;
        if (p == 1)
           dado = removerInicio(l);
        else {
           int pos = 1;
           bloco *tmp = *l;
           bloco *ant = NULL;

           while (pos < p && tmp->prox != NULL) {
             ant = tmp;
             tmp = tmp->prox;
             pos++;
           }

           dado = tmp->dado;
           ant->prox = tmp->prox;
           free(tmp);
        }
        return dado;
    }
}

void inserirOrdenado(lista **l, int d) {
    if (!listaVazia(*l)) {
        
        int pos = 1;
        bloco *tmp = *l;

        while (tmp->dado < d) {
            if (tmp->prox == NULL) {
                pos++;
                break;
            } else {
                tmp = tmp->prox;
                pos++;
            }
        }
        inserirPosK(l, pos, d); 
    } else {
       inserirInicio(l, d);
    }
}

void imprimirLista (lista *l) {

    if (!listaVazia(l)) {
        bloco *tmp = l;

        while (tmp != NULL) {
            printf ("\nElemento: %d", tmp->dado);
            tmp = tmp->prox;
        }
    }
}
