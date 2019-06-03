#include <stdio.h>
#include <stdlib.h>


int main(){

    int *vet;
    int n, i,flag=0;

    printf("Digite o tamanho do vetor:\n");
    scanf("%d", &n);

    if(!(vet = malloc( n * sizeof(int) )))
        exit(1);

     printf("Digite os numeros do vetor\n");

    for(i=0; i<n; i++)
        scanf("%d", &vet[i]);

    for(i=0; i<n-1; i++){
        if(vet[i] > vet[i+1])
            flag++;
    }
    if(!flag)
            printf("ORDENADO\n");

    free(vet);
}
