#include <stdio.h>
#include <stdlib.h> // Para a função malloc()

void teste(int *numero){
    *numero = 10;
}

int main(int argc, char const *argv[]){
    int *numero = malloc(sizeof(int)); // Aloca memória para um inteiro
    if (numero == NULL) { // Verifica se a alocação de memória falhou
        printf("Erro: Não foi possível alocar memória.\n");
        return 1;
    }

    teste(numero);
    printf("%d\n", *numero); // Espera: 10

    free(numero); // Libera a memória alocada
    return 0;
}
