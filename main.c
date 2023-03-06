#include "lista.c"

int main (void) {
    lista *lst;

    criarLista(&lst);

    inserirOrdenado(&lst, 3);
    inserirOrdenado(&lst, 4);
    inserirOrdenado(&lst, 1);
    inserirOrdenado(&lst, 2);
    inserirOrdenado(&lst, 5);
    inserirOrdenado(&lst, 7);
    inserirOrdenado(&lst, 6);

    imprimirLista(lst);
    printf("\n\n");
}