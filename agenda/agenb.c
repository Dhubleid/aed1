#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenb.h"

void *pB = NULL; // Ponteiro void buffer - todos dados, valores etc armazenados nele

//ponteiros abaixo em ordem que estao amazenados no buffer

int *qnt = NULL; // Guarda o numero de srructs(pessoas) da agenda
int *i = NULL; // variavel auxiliar
int *j = NULL;// variavel auxiliar
int *opc = NULL;// variavel para as opcoes do switch
int *aux = NULL;

char *auxc = NULL;// string auxiliar

//ponteiros para as structs(pessoas) da agenda

agenda *pessoa = NULL;
agenda *pessoa2 = NULL;
agenda *auxAg = NULL;

void novoContato()
{
    (*qnt)++;

    realoca();

    aponta();

    pessoa = pB + 5 * sizeof(int) + 60 * sizeof(char) + sizeof(agenda) + (*qnt-1) * sizeof(agenda);

    printf("Nome do novo contato: \n");
    scanf("%[^\n]", &pessoa->nome);

    printf("Numero do novo contato: \n");
    scanf("%d", &pessoa->num);
}

agenda *buscaContato()
{
    printf("Digite o nome: \n");
    scanf("%[^\n]s", auxc);
    getchar();

    pessoa = pB + 5 * sizeof(int) + 60 * sizeof(char) + sizeof(agenda);

    for(*i=0; *i<*qnt; (*i)++){

        if(!strcmp(pessoa->nome,auxc))
            return pessoa;

        pessoa++;
    }
    return NULL;
}

void apagarContato()
{
    if(!(*qnt)){
        printf("lista vazia\n");
        return;
    }

    if ( !(pessoa = buscaContato()) ){
        printf("Nome nao encontrado\n");
        return;
    }

    pessoa2 = pessoa+1;

    for(*i=0; *i<(*qnt-1); (*i)++){
        *pessoa = *pessoa2;
        pessoa++;
        pessoa2++;
    }

    (*qnt)--;

    realoca();

    aponta() ;
}

void listarContatos()
{
    if(*qnt == 0)
        printf("\nAgenda Vazia\n\n");

        else{
            pessoa = pB + 5 * sizeof(int) + 60 * sizeof(char) + sizeof(agenda);
            for(*i=0; *i<*qnt; (*i)++){
                printf("Nome: %s\n", pessoa->nome);
                printf("Numero: %d\n\n", pessoa->num);
                pessoa++;
            }
        }
}

void realoca()
{
        if(!(pB = realloc(pB, 5 * sizeof(int) + 60 * sizeof(char) + sizeof(agenda) + (*qnt) * sizeof(agenda))))
        exit(1);
}

void aponta()
{
    //enderçando os ponteiros nesessarios
    qnt = pB;
    i = pB + sizeof(int);
    j = pB + 2 * sizeof(int);
    opc = pB + 3 * sizeof(int);
    aux = pB + 4 * sizeof(int);

    auxc = pB + 5 * sizeof(int);

    auxAg = pB + 5 *sizeof(int) + 60 * sizeof(char);
}
