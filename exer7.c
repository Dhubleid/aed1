#include <stdio.h>
#include <stdlib.h>

int ordenado(int *vet, int n);
void insere(int *vet, int n);

int main()
{
    int *vet;
    int n, i, ord=0;
    int num;

    printf("Digite o tamanho do vetor:\n");
    scanf("%d", &n);

    if(!(vet = malloc( n * sizeof(int) )))
        exit(1);

    while(!ord){

        printf("Digite os numeros do vetor:\n");

        for(i=0; i<n; i++)
            scanf("%d", &vet[i]);

        ord = ordenado(vet, n);

        if(!ord)
            printf("Vetor nao eh ordenado!\n");
    }

    printf("Digite o numero para busca:\n");
    scanf("%d", &num);

    for(i=0; i<n; i++){
        if(vet[i] == num){
                printf("Numero encontrado na possicao: %d do vetor\n", i);
                break;
        }

        if( i == n-1)
            printf("Numero nao encontrado\n");
     }


    free(vet);

    return 0;

}

int ordenado(int *vet, int n)
{
   int i, j;
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++)
            if(vet[j] > vet[j+1])
                return 0;

        return 1;
    }
    return 1;
}

void insere(int *vet, int n)
{
    int i, j, key;

    for(i=0; i<n; i++){
        key = vet[i];
        j = i - 1;
        while(j >= 0 && vet[j] > key){
            vet[j+1] = vet[j];
            j--;
        }
        vet[j+1] = key;
    }
}
