#include <stdio.h>
#include <stdlib.h>

void troca(int *x, int *y)
{
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

void insere(int *vet, int n, int *c);

int main()
{

    int vet[] = {72, 12, 62, 69, 27, 67, 41, 56, 33, 74};
    int n, i, count = 0;

    n = sizeof(vet) / sizeof(int);


    insere(vet, n, &count);

    for(i=0; i<n; i++)
        printf("%d ", vet[i]);

    printf("\nTrocas para ordenar: %d ", count);

}

void insere(int *vet, int n, int *c)
{
    int i, j, key;

    for(i=1; i<n; i++){
        key = vet[i];
        j = i - 1;
        while(j >= 0 && vet[j] > key){
            vet[j+1] = vet[j];
            j--;
            (*c)++;
        }
        vet[j+1] = key;
    }
}
