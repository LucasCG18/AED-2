#include <stdio.h>
#include <math.h>
 
void quickSort(int A[],int p, int r){
    int q;
    if (p<r){
        q = partition(A,p,r);
        quickSort(A,p,q-1);
        quickSort(A,q+1,r);
    }
}
int partition(int A[], int p, int r){
    int i,j,x, aux,vetor[3],posicao[3];
    vetor[0] = A[0];
    vetor[1] = A[(p+r)/2];
    vetor[2] = A[r-1];
    posicao[0] = 0;
    posicao[1] = (p+r)/2;
    posicao[3] = r-1;
    for (i = 0; i < 3; i++){
        for(j = 0; j < 3 - i; j++){
            if (j < 3 - 1 && vetor[j] > vetor[j + 1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
                aux = posicao[j];
                posicao[j] = posicao[j+1];
                posicao[j+1] = aux;
            }
        }
    }
    x = vetor[1];
    aux = A[r];
    A[r] = A[posicao[1]];
    A[posicao[1]] = aux;
    i = p-1;
    for (j = p; j < r; j++)
    {
        if (A[j] < x)
        {
            i++;
            aux = A[j];
            A[j] = A[i];
            A[i] = aux;
        }
    }
    aux = A[r];
    A[r] = A[i+1];
    A[i+1] = aux;
    return i+1;
}
 
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
    quickSort(A, 0, sizeof(A)/sizeof(int));
    printf("\nDepois de serem organizados:" );
    for (int i = 0; i < 10; i++)
    {
        printf(" %d", A[i]);
    }
}