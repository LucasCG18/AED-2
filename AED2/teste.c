#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void max_heapfy(char **strings, int pai, int tamanho) {
    int e = pai * 2, d = pai * 2 + 1, max = pai, i;
    char aux[20];
    if (e <= tamanho && strcmp(strings[e], strings[pai]) > 0) {
        max = e;
    }
    if (d <= tamanho && strcmp(strings[d], strings[max]) > 0) {
        max = d;
    }
    if (max != pai) {
        strcpy(aux, strings[max]);
        strcpy(strings[max], strings[pai]);
        strcpy(strings[pai], aux);
        max_heapfy(strings, max, tamanho);
    }
}

void build_max_heap(char **strings, int tamanho) {
    int i;
    for (i = tamanho / 2; i >= 1; i--) {
        max_heapfy(strings, i, tamanho);
    }
}

char* heap_extract_max(char **strings, int tamanho) {
    char max[20];
    if (tamanho > 1) {
        strcpy(max, strings[1]);
        strcpy(strings[1], strings[tamanho]);
        tamanho--;
        max_heapfy(strings, 1, tamanho);
        return max;
    } else {
        return strings[tamanho];
    }
}

void heapSort(char **strings, int tamanho) {
    char **ord_strings;
    int i;
    ord_strings = malloc((tamanho + 1) * sizeof(char*));
    for (i = 1; i <= tamanho; i++) {
        ord_strings[i] = malloc(sizeof(char) * 20);
    }
    build_max_heap(strings, tamanho);

    for (i = tamanho; i >= 1; i--) {
        strcpy(ord_strings[i], heap_extract_max(strings, i));
    }
    printf("palavras:");
    for (i = 1; i <= tamanho; i++) {
        printf(" %s", ord_strings[i]);
    }
    for (i = 1; i <= tamanho; i++) {
        free(ord_strings[i]);
    }
    free(ord_strings);
}

int main() {
    // Exemplo de uso
    char *strings[] = {"", "banana", "abacaxi", "uva", "laranja", "manga"};
    int tamanho = 5;
    heapSort(strings, tamanho);
    return 0;
}
