//Arquivo com o metodo de Selection Sort de ordenação, comentado, ele se baseia escolhendo o menor numero do vetor a frente e leva ele pra posição inicial do laço de repetição
#include <stdlib.h>

void selectionSort(int A[], int tam_A){
    int i,j,minimo,posicai_menor, aux;
    //Esse loop, vai ser o que vai percorrer todas as posiçoes do vetor, tomando sempre a posição em que estiver como suposto minimo
    for (i = 0; i < tam_A; i++)
    {
        posicai_menor = -1;
        //atribuindo a posição atual como minimo
        minimo = A[i];
        //Esse loop, vai ser o que vai procurar o menor elemento do array e trocar com o minimo, se houver um menor que o minimo atual
        for (j = i+1; j < tam_A; j++)
        {
            //teste paara ver se o minimo é maior que algum elemento
            if (minimo > A[j])
            {
                posicai_menor = j;
                minimo = A[j];
            }
        }
        //aqui troca os elementos se houver necessidade
        if (posicai_menor  != -1)
        {
            aux = A[i];
            A[i] = minimo;
            A[posicai_menor] = aux;
        }
    }
}

//teste do algoritimo
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
    selectionSort(A, sizeof(A)/sizeof(int));
    printf("\nDepois de serem organizados:" );
    for (int i = 0; i < 10; i++)
    {
        printf(" %d", A[i]);
    }
}