#include <stdio.h>
#include <stdlib.h>

void troca(int *x, int *y)
{
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

void quickSort(int *vet, int esquerda, int direita);

int main()
{

    int vet[] = {26, 65, 45, 73, 10, 18, 78, 93, 70, 49, 23, 22};
    int n, i;

    n = sizeof(vet) / sizeof(int);


   quickSort(vet, 0, n-1);

    for(i=0; i<n; i++)
        printf("%d ", vet[i]);

}

void quickSort(int *vet, int esquerda, int direita)
{
    int meio, i, j;
    i = esquerda;
    j = direita;
    meio = vet[(direita + esquerda) / 2];

    do {
        while(vet[i] < meio)
            i++;
        while (meio < vet[j])
            j--;
        if(i <= j){
            troca(&vet[i], &vet[j]);
            i++;
            j--;
        }
    }while(i <= j);

    if (esquerda < j)
        quickSort(vet, esquerda, j);

    if (i < direita)
        quickSort(vet, i ,direita);
}


