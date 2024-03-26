// Arqiovo com o metodo de Merge sort de ordenação, comentado, esse é um codigo um pouco mais complicado, é ultilizado atravez d recurção, ele divide vai dividindo e ordenando de baixo para cima resumidamentee
//ultilizando do metodo dividir para conquistar
#include <stdlib.h>
#include <math.h>

int mergeSort(int A[],int p, int r){
    int q;
    if (p < r)
    {
        q = p + (r - p)/2;
        mergeSort(A,p,q);
        mergeSort(A,q+1,r);
        merge(A,p,q,r);
    }
    
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void merge(int A[], int p, int q, int r){
    int n1, n2, L[q - p + 1 + 1], R[r - q + 1], i,j, k;
    n1 = q - p + 1;
    n2 =  r - q;
    
    for(i = 0; i < n1; i++){
        L[i] = A[p + i];
    }
    for(j = 0; j < n2; j++){
        R[j] = A[q + j + 1];
        //printf("--->%d", A[q + j]);
    }
    L[n1 + 1] = INT_MAX;
    R[n2 + 1] = INT_MAX;
    i = j = 0;
    for(k = p ; k <= r ; k++){
        if (L[i] < R[j])
        {
            A[k] = L[i];
            i = i + 1;
        }else{
            A[k] = R[j];
            j = j + 1 ;
        }
    }
}

//teste do insection sort
int main(){
    int A[10];
    for (int i = 10, j = 0; i > 0; i--, j++)
    {
        //A[j] = rand()%99;
        A[j] = i;
    }
    printf("Antes de serem organizados:" );
    for (int i = 0; i < 10; i++)
    {
        printf(" %d", A[i]);
    }
    mergeSort(A, 0, sizeof(A)/sizeof(int) - 1);
    printf("\nDepois de serem organizados:" );
    for (int i = 0; i < 10; i++)
    {
        printf(" %d", A[i]);
    }
}