// Lucas Castelani Gouveia 168877
#include <stdio.h>
#include <string.h>

void max_heapfy(char **strings, int pai, int tamanho){ 
    //criando as variaveis necessarias para arrumar a arvore
    int e = pai * 2,d = pai * 2 + 1, max = 0,i;
    char aux[20];

    //verificando se a arvore tem filhos a esquerda, se tiver ver se ele vem antes ou depois em ordem alfabetica do pai
    if (e<=tamanho && strcmp(strings[e],strings[pai]) > 0)
    {
        max = e;
    }else{
        max = pai;
    }
    //verificando se a arvore tem filhos a direta, se tiver ver se ele vem antes ou depois em ordem alfabetica do elemento que foi selecionado como max
    if(d<=tamanho && strcmp(strings[d],strings[max]) > 0){
        max = d;
    }
    //se o elemento selecionado como max for diferente do pai, então deve haver mudanças na arvore
    if (max != pai)
    {
        strcpy(aux,strings[max]);
        strcpy(strings[max], strings[pai]);
        strcpy(strings[pai], aux);
        max_heapfy(strings,max,tamanho);
    }
    /*for (i = 1; i <= tamanho; i++)
    {
        printf("--->%s", strings[i]);
    }*/
}
void build_max_heap(char **strings,int tamanho){
    //contruindo a arvore pelo tamanho do vetor
    int i;
    for (i = tamanho/2; i > 0; i--)
    {
        max_heapfy(strings,i,tamanho);
    }
    
}
void heap_extract_max(char **strings, int tamanho, char*max) {
    //pegando o maior elemento e depois substituindo ele pelo elemento mais a direita para reconstruir a arvore
    if (tamanho >= 1) {
        strcpy(max, strings[1]);
        strcpy(strings[1], strings[tamanho]);
        tamanho = tamanho - 1;
        max_heapfy(strings, 1, tamanho);
    } else {
        max = strings[tamanho];
    }
}
void heapSort(char **strings,int tamanho){
    //criando as variaveis e alocando os vetores
    char **ord_strings, *max = malloc(sizeof(char)*20);
    int i;
    ord_strings = malloc(sizeof(char*) * (tamanho + 1));
    for (i = 1; i <= tamanho; i++)
    {
        ord_strings[i] = malloc(sizeof(char) * 20);
    }

    //contruindo a "arvore" pela primeira vez
    build_max_heap(strings,tamanho);
    printf("build_heap:");
    for (i = 1; i <= tamanho; i++) {
        printf(" %s", strings[i]);
    }
    printf("\n");

    //ordenando de traz pra frente, pegando sempre o de cima da arvore
    for (i = tamanho; i >= 1; i--)
    {
        heap_extract_max(strings,i,max);
        strcpy(ord_strings[i],max);
    }

    //printando as palavras ordenadas
    printf("palavras:");
    for (i = 1; i <= tamanho; i++)
    {
        printf(" %s", ord_strings[i]);
    }

    //liberando espaço dos vetores alocados
    for (i = 0; i <= tamanho; i++) {
        free(ord_strings[i]);
    }
    free(ord_strings);
    free(max);
}

int main() {
    int N, M, *palavras, i, j, condicao = 0;
    char **str, **ord_str, c;

    scanf("%d", &N);
    str = malloc(sizeof(char*) * N);
    for (i = 0; i < N; i++) {
        str[i] = malloc(sizeof(char) * 20);
        scanf("%s", str[i]);
    }
    //aqui peercorre todas as palavras para ver se há algum caractere que seja invalido
    for (i = 0; i < N; i++)
    {
        for (j = 0, c = str[i][j]; j < 20 && c >= 97 && c<=122; j++, c = str[i][j]);
        if (c != 0)
        {
            printf("a palavra %s eh invalida", str[i]);
            i = N;
            condicao = 1;
        }
    }

    //aqui recebe quantas palavras vao ser ordenadas e quais as posições delas
    scanf("%d", &M);
    palavras = malloc(sizeof(int) * M);
    for (i = 0; i < M; i++) {
        scanf("%d", &palavras[i]);
    }

    //aqui coloca as palavras seleecionadas no vetor que vai ser usado posteriormente como o vetor ha ser arrumado
    ord_str = malloc(sizeof(char*) * (M + 1));
    for (i = 1; i <= M; i++) {
        ord_str[i] = malloc(sizeof(char) * 20);
        strcpy(ord_str[i], str[palavras[i-1]]);
    }
    if (condicao == 0)
    {
        //se não houver palavras invalidas
        //chama o heapsort
        heapSort(ord_str, M);
    }
    
    

    // Libere a memória alocada
    for (i = 0; i < N; i++) {
        free(str[i]);
    }
    free(str);

    for (i = 0; i <= M; i++) {
        free(ord_str[i]);
    }
    free(ord_str);
    free(palavras);

    return 0;
}