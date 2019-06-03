#include <stdio.h>
#include <stdlib.h>

void troca(int *x, int *y)
{
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

int main()
{

    int *vet;
    int n, i, j, ordenado;

    printf("Digite o tamanho do vetor:\n");
    scanf("%d", &n);

    if(!(vet = malloc( n * sizeof(int) )))
        exit(1);

     printf("Digite os numeros do vetor\n");

    for(i=0; i<n; i++)
        scanf("%d", &vet[i]);

    for(i=0; i<n-1; i++){
        ordenado = 1;
        for(j=0; j<n-i-1; j++)
            if(vet[j] < vet[j+1]){
                troca(&vet[j], &vet[j+1]);
                ordenado = 0;
            }
        if(ordenado)
                break;
    }

       for(i=0; i<n; i++)
            printf("%d ", vet[i]);
    free(vet);
}
