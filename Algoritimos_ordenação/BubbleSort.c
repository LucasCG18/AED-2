// Arqiovo com o metodo de Bubble sort de ordenação, comentado, o bubble sort consiste em pegar a primeira posição do vetor e verificar se é maior que o proximo elemento, se for, trocar de posição com ele ee testar com o proximo
#include <stdlib.h>

void bubbleSort(int A[], int tam_A){
    int i, j, aux;
    //Esse loop, passara por todo o vetor com o loop principal dentro
    for (i = 0; i < tam_A; i++){
        //Esse loop, vai empurrando sempre o maior numero para o final
        for(j = 0; j < tam_A - i; j++){
            //Aqui ha a troca dos elementos se o elemento atual for maior que o proximo elemento
            if (j < tam_A - 1 && A[j] > A[j + 1])
            {
                aux = A[j];
                A[j] = A[j+1];
                A[j+1] = aux;
            }
        }
    }
}

//teste do algoritimo
int main(){
    int A[10];
    for (int i = 10, j = 0; i > 0; i--, j++)
    {
        //A[j] = rand()%99;
    }
    printf("Antes de serem organizados:" );
    for (int i = 0; i < 10; i++)
    {
        printf(" %d", A[i]);
    }
    bubbleSort(A, sizeof(A)/sizeof(int));
    printf("\nDepois de serem organizados:" );
    for (int i = 0; i < 10; i++)
    {
        printf(" %d", A[i]);
    }
}