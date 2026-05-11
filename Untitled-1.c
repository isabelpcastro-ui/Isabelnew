//stack menor qe heap
//vetor[1000] => +- 4kb

//importante liberar memoria!! o programa pode encerrar e a memoria nao ser liberada - heap dura ate q libere

/*
Malloc (Memory Allocation)
-
    void *malloc (unsigned int num);
    (passa o tamanho de memoria q vc quer alocar)
-
Calloc (C Allocation)
-
    void *calloc (unsigned int num, unsigned int size);
    (passa o peso na memoria e o tamanho da qnt de dados)
-
Realloc (Reallocation)
-
    void *realloc (void *ptr, unsigned int num);
    (passa o ponteiro e o tamanho do ponteiro) (nao perde a referencia dos seu dado)
-
Free
    void free (void *p);


Inicializar utilizando Calloc(preferencial!!!) ou
                       Malloc(como geralmente utilizamos)

*/



/*exemplo de malloc -> deixam acessar fora
int main()
{
    int *v = (/_typecast pois eh uma func generica_/ int *) malloc (4 * sizeof(int));
    printf("%d" ,v[5]);
    free(v);
}
*/

/*exemplo de malloc -> esquecer de free()
int main()
{
    int *v = (int *) malloc (4 * sizeof(int));
    int *w = (int *) malloc (10 * sizeof(int));
    w = v;
    o ponteiro sem free acaba perdendo sua direcao ao receber um outro ponteiro q aponta para um outro endereco
    com 4 bytes
}
*/

/* teste p/ ver se deu problema
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *v = (int *) malloc (4 * sizeof(int));
    if (v == NULL) {
        printf("Problema na alocacao!");
        return 1;
    }
    v[0] = 1;
    free(v);
    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>

void inicializa_vetor(int *a, int tamanho, int valor) {
    int i;
    for (i = 0; i < tamanho; i++)
        a[i] = valor;
}


int main()
{
    int qtdALunos;
    float *alunos, soma = 0, media;

    scanf("%d" ,&qtdALunos);

    inicializa_vetor(alunos, qtdALunos, 0);

    alunos = (float *)calloc(sizeof(float), qtdALunos);

    for (int i = 0; i < qtdALunos; i++)
    {
        scanf("%f" ,&alunos[i]);
    }
    
    for (int i = 0; i < qtdALunos; i++)
    {
        media += alunos[i];
    }
    media/=qtdALunos;

    for (int i = 0; i < qtdALunos; i++)
    {
        soma += pow((alunos[i] - media),2);
        /* code */
    }
    soma = sqrt(soma/qtdALunos);
    
    printf("resultado SD : %.2f" ,soma);

}