#include <stdio.h>
#include <stdlib.h>
#include "agenb.h"
#include "ordenacao.h"

int main()
{

    if( !( pB = malloc(5 * sizeof(int) + 60 * sizeof(char) + sizeof(agenda) ) ) )
            exit(1);

    aponta();

    *qnt = 0;

    do{
       printf("1 - Novo Contato\n2 - Busca\n3 - Apagar Contato\n4 - Listar Contatos\n5 - Insertion\n6 - Select\n0 - Sair\n");
       scanf("%d", opc);
       getchar();
       printf("\n");

       switch(*opc){

       case 1:
            novoContato();
       break;

       case 2:
            if(!(*qnt))
                printf("lista vazia\n");
            else{
                if(pessoa = buscaContato()){
                    printf("\nNome: %s\n", pessoa->nome);
                    printf("Numero: %d\n\n", pessoa->num);
                }else
                    printf("Nome nao encontrado!\n");
                }
       break;

       case 3:
            apagarContato();
       break;

       case 4:
            pessoa = pB + 5 * sizeof(int) + 60 * sizeof(char) + sizeof(agenda);
            listarContatos();
       break;

       case 5:
            insertionSort();
       break;

       case 6:
            selectSort();
       break;

       case 0:
       break;

       default :
        printf("\nOpcao Invalida\n");
       }

    }while(*opc != 0);

    free(pB);

    return 0;
}

