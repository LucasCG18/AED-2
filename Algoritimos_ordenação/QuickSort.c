#include <stdlib.h>
#include <math.h>

void QuickSort(int A[],int p,int r){
    
    if(p<r){
        int q = partition(A,p,r);
        QuickSort(A,p,q-1);
        QuickSort(A,p,q+1);
    }
}

int partition(int A[],int p,int r){
    
    return p;
}