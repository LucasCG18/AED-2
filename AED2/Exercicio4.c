#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
void quickSort_variantePartition(int A[],int p, int r, int *profundidades, int profundidade){
    int q;
    if (p<r){
        q = partition_variante(A,p,r);
        quickSort_variantePartition(A,p,q-1, profundidades, profundidade + 1); 
        quickSort_variantePartition(A,q+1,r,profundidades, profundidade + 1);
    }else if(r<=p){
        if (profundidade > profundidades[0])
        {
            profundidades[0] = profundidade;
        }
        if (profundidade < profundidades[1])
        {
            profundidades[1] = profundidade;
        }
    }
}
int partition_variante(int A[], int p, int r){
    int i,j,x, aux,vetor[3],posicao[3];
    vetor[0] = A[p];
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
    if (vetor[0] == vetor[1])
    {
        posicao[1] = (posicao[1] < posicao[0]) ? posicao[0] : posicao[1];
    }
    x = vetor[1];
    aux = A[r];
    A[r] = A[posicao[1]];
    A[posicao[1]] = aux;
    i = p-1;
    for (j = p; j <= r; j++)
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
void quickSort(int A[],int p, int r, int *profundidades, int profundidade){
    int q;
    if (p<r){
        q = partition(A,p,r);
        quickSort(A,p,q-1, profundidades, profundidade + 1);
        quickSort(A,q+1,r, profundidades, profundidade + 1);
    }else if(r<=p){
        printf("\n %d %d %d", profundidades[0], profundidades[1], profundidade);
        if (profundidade > profundidades[0])
        {
            profundidades[0] = profundidade;
        }
        if (profundidade < profundidades[1])
        {
            profundidades[1] = profundidade;
        }
    }
}
int partition(int A[], int p, int r){
    int i,j,x, aux;
    x = A[r];
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
    int i,j,n, *A, *B, profundidades[2];
    profundidades[0] = 0;
    profundidades[1] = 10000;
    scanf("%d",&n);
    A=malloc(sizeof(int)*n);
    B=malloc(sizeof(int)*n);
    for (i = 0; i < n; i++)
    {
        scanf("%d",&A[i]);
        B[i] = A[i];
    }
    quickSort(B,0,n-1,profundidades,0);
    printf("%d",profundidades[0]-profundidades[1]);
    profundidades[0] = 0;
    profundidades[1] = 10000;
    quickSort_variantePartition(A, 0, n-1, profundidades, 0);
    printf("\n%d",profundidades[0]-profundidades[1]);

    free(A);
    free(B);
}