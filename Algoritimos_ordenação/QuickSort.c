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