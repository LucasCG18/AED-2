// Lucas Castelani Gouveia
#include <stdio.h>
#include <stdlib.h>
 
typedef struct lista
{
    int valor;
    struct lista *prox;
}No;
typedef No* PNo;

PNo liberar (PNo lista) {
    PNo aux;
    for (aux = lista; aux != NULL; aux = lista) { 
        lista = lista->prox; 
        free(aux); 
    }
    return NULL; 
}
PNo inserirFim (PNo lista, int v) {
    PNo novo = (PNo) malloc (sizeof(No));
    PNo ant, paux;
    novo->valor = v;
    novo->prox = NULL;
    for (ant = NULL, paux = lista; paux != NULL; paux = paux->prox) ant = paux;
    if (ant == NULL) lista = novo; 
    else ant->prox = novo; 
    return lista; 
}
PNo merge(PNo Elista,PNo Dlista) {
    int i, j, k, meio;
    PNo aux1 = NULL, aux2 = NULL, lista = NULL;
    aux1 = Elista;
    aux2 = Dlista;
    while (aux1 != NULL && aux2 != NULL) {
        if (aux1->valor <= aux2->valor) {
            lista = inserirFim(lista, aux1->valor);
            aux1 = aux1->prox;
        }
        else {
            lista = inserirFim(lista, aux2->valor);
            aux2 = aux2->prox;
        }
    }

    // Se uma das listas ainda tiver elementos, anexa-os ao final da lista resultante
    while (aux1 != NULL) {
        lista = inserirFim(lista, aux1->valor);
        aux1 = aux1->prox;
    }

    while (aux2 != NULL) {
        lista = inserirFim(lista, aux2->valor);
        aux2 = aux2->prox;
    }
    return lista;
}
 
PNo mergeSort(PNo lista, int tamanho, int profundidade, int *pro_fim) {
    int meio, i;
    PNo aux = lista, Elista = NULL, Dlista = NULL;
    if (tamanho > 1)
    {
        if (tamanho % 2 ==0){
            meio = tamanho/2;
        }else{
            meio = tamanho/2 + 1;
        }
        for (i = 0; i < meio - 1; i++)
        {
            aux = aux->prox;
        }
        Dlista = aux->prox;
        aux->prox = NULL;
        Elista = lista;

        
        Elista = mergeSort(Elista, meio, profundidade + 1, pro_fim);
        Dlista = mergeSort(Dlista, tamanho/2, profundidade + 1, pro_fim);
        lista = merge(Elista, Dlista);
    }
    if (tamanho == 1 && *pro_fim < profundidade)
    {
        *pro_fim = profundidade;
    }
    
    return lista;
}
 
 
void printArray(int A[], int size) {
    int i;
    for (i = 0; i < size; i++)
    printf("%d ", A[i]);
    printf("\n");
}
 
int main() {
    int n, i, valor, *profundidade;
    profundidade = malloc(sizeof(int));
    *profundidade = 0;
    PNo lista = NULL, aux = NULL;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
       scanf("%d", &valor);
       lista = inserirFim(lista, valor);
    }
    lista = mergeSort(lista, n, 0, profundidade);
    for (aux = lista; aux != NULL; aux = aux->prox)
    {
        printf("%d ", aux->valor);
    }
    printf("\n%d", *profundidade);
    free(profundidade);
    lista = liberar(lista);
    //vlw
}