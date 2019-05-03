#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct agenda{
    char nome[30];
    int num;
}agenda;

void novoContato();
agenda *buscaContato();
void apagarContato();
void listarContatos();
void aponta(); // função para ajustar os ponteiros após os reallocs e malloc


void *pB = NULL; // Ponteiro void buffer - todos dados, valores etc armazenados nele

//ponteiros abaixo em ordem que estao amazenados no buffer

int *qnt = NULL; // Guarda o numero de srructs(pessoas) da agenda
int *i = NULL; // variavel auxiliar
int *j = NULL;// variavel auxiliar
int *opc = NULL;// variavel para as opcoes do switch

char *auxc = NULL;// string auxiliar

//ponteiros para as structs(pessoas) da agenda

agenda *pessoa = NULL;
agenda *pessoa2 = NULL;

int main()
{

    if( !( pB = malloc(4 * sizeof(int) + 30 * sizeof(char) ) ) )
            exit(1);

    aponta();

    *qnt = 0;

    do{
       printf("1 - Novo Contato\n2 - Busca\n3 - Apagar Contato\n4 - Listar Contatos\n0 - Sair\n");
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

       case 4: pessoa = pB + 4 * sizeof(int) + 30 * sizeof(char);
            listarContatos();
       break;

       case 0:
       break;

       default :
        printf("\nOpcao Invalida\n");
       }

    }while(*opc != 0);

    return 0;
}

void novoContato()
{
    (*qnt)++;


    if(!(pB = realloc(pB, 4 * sizeof(int) + 30 * sizeof(char) + (*qnt) * sizeof(agenda))))
        exit(1);

    aponta();

    pessoa = pB + 4 * sizeof(int) + 30 * sizeof(char) + (*qnt-1) * sizeof(agenda);

    printf("Nome do novo contato: \n");
    scanf("%[^\n]", &pessoa->nome);

    printf("Numero do novo contato: \n");
    scanf("%d", &pessoa->num);


}

agenda *buscaContato()
{

    printf("Digite o nome: \n");
    scanf("%[^\n]s", auxc);

    pessoa = pB + 4 * sizeof(int) + 30 * sizeof(char);

    for(*i=0; *i<*qnt; (*i)++){

        if(!strcmp(pessoa->nome,auxc))
            break;

        pessoa++;
    }

       return !strcmp(pessoa->nome,auxc)? pessoa : NULL;

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
        memcpy(pessoa,pessoa2,sizeof(agenda));
        pessoa++;
        pessoa2++;
    }


    (*qnt)--;

    if(!(pB = realloc(pB, 4 * sizeof(int) + 30 * sizeof(char) + *qnt * sizeof(agenda))))
        exit(1);

    aponta() ;
}

void listarContatos()
{
    if(*qnt == 0)
        printf("\nAgenda Vazia\n\n");

        else{
            pessoa = pB + 4 * sizeof(int) + 30 * sizeof(char);
            for(*i=0; *i<*qnt; (*i)++){
                printf("Nome: %s\n", pessoa->nome);
                printf("Numero: %d\n\n", pessoa->num);
                pessoa++;
            }
        }
}

void aponta()
{
    //enderçando os ponteiros nesessarios
    qnt = pB;
    i = pB + sizeof(int);
    j = pB + 2 * sizeof(int);
    opc = pB + 3 * sizeof(int);
    auxc = pB + 4 * sizeof(int);
}
