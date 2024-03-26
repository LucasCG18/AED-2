//Lucas Castelani Gouveia 168877

#include <stdio.h>
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
int main()
{
    int N, *pacientes,*doses, i, aux = 0;
    scanf("%d", &N);
    pacientes= malloc(sizeof(int)* N);
    doses = malloc(N * sizeof(int));
    for (i = 0; i < N; i++)
    {
        scanf("%d", &pacientes[i]);
    }
    for (i = 0; i < N; i++)
    {
        scanf("%d", &doses[i]);
    }
    bubbleSort(pacientes, N);
    bubbleSort(doses, N);
    for (i = 0; i < N; i++)
    {
        if (doses[i] <= pacientes[i])
        {
            aux = -1;
        }
    }
    if (aux != -1)
    {
        printf("sim");
    }else{
        printf("nao");
    }
    free(pacientes);
    free(doses);
    return 0;
}

