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
    vetor[2] = A[r];
    posicao[0] = p;
    posicao[1] = (p+r)/2;
    posicao[2] = r;
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
    //printf("Numero: %d, Posicao: %d", vetor[0], posicao[0]);
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
    int i,j,n, *A;
    scanf("%d",&n);
    A=malloc(sizeof(int)*n);
    for (i = 0; i < n; i++)
    {
        scanf("%d",&A[i]);
    }
    printf("Antes de serem organizados:" );
    for (int i = 0; i < n; i++)
    {
        printf(" %d", A[i]);
    }
    quickSort(A, 0, n-1);
    printf("\nDepois de serem organizados:" );
    for (int i = 0; i < n; i++)
    {
        printf(" %d", A[i]);
    }
}