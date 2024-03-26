// Arqiovo com o metodo de insection sort de ordenação, comentado, o insection sort organiza pegando um valor e testando com os elementos anteriores para haver uma possivel substituição
#include <stdlib.h>
void insectionSort (int A[], int tam_A){
    int i,j, chave;
    // Aqui começa o loop para ordenação, onde começa da 2 posição do vetor
    for (j = 1; j < tam_A; j++)
    {
        //aqui a chave é escolhida, como a segunda posição do vetor, para haver uma possiveel troca de valores posteriormente
        chave = A[j];
        i = j - 1;
        //Nesse loop, vai haver os testes que devem seer feitos com os elementos anteriores
        while (i >= 0 && A[i] > chave)
        {
            //aqui os numero vao sendo colocados em uma casa para frente até chegar em uma posição que a chave vai ser maior que o numero testado atualmente
            A[i + 1] = A[i];
            i--;
        }
        //Aqui a chave é inserida na posição  em que ela é maior que o numero anterior e menor que o proximo
        A[i + 1] = chave;
    }
}
//teste do insection sort
int main(){
    int A[10];
    for (int i = 10, j = 0; i > 0; i--, j++)
    {
        A[j] = rand()%99;
    }
    printf("Antes de serem organizados:" );
    for (int i = 0; i < 10; i++)
    {
        printf(" %d", A[i]);
    }
    insectionSort(A, sizeof(A)/sizeof(int));
    printf("\nDepois de serem organizados:" );
    for (int i = 0; i < 10; i++)
    {
        printf(" %d", A[i]);
    }
}