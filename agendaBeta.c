#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct agenda{
    char nome[30];
    int num;
}agenda;


void novoContato();
agenda *buscaContato();
void apagarContato();
void listarContatos();
void realoca();
void aponta(); // função para ajustar os ponteiros após os reallocs e malloc
int *comparaString(char *str, char *str2);
void insertionSort();
void selectSort();


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

void insertionSort()
{
    for(*i=1; *i<*qnt; (*i)++){

        pessoa2 = pB + 5 * sizeof(int) + 60 * sizeof(char);
        pessoa = pB + 5 * sizeof(int) + 60 * sizeof(char) + sizeof(agenda) + *i * sizeof(agenda);

        *pessoa2 = *pessoa;

        *j = *i - 1;

        pessoa = pB + 5 * sizeof(int) + 60 * sizeof(char) + sizeof(agenda) + *j * sizeof(agenda);

        while(*j >= 0 && (comparaString(pessoa->nome, pessoa2->nome))){
            *(pessoa + 1) = *pessoa;
            (*j)--;
            pessoa--;
        }
       *(pessoa + 1) = *pessoa2;
    }
}

void selectSort()
{

    for(*i=0; *i<*qnt-1; (*i)++){

        *aux = *i;
        *j = *i + 1;

        pessoa2 = pB + 5 * sizeof(int) + 60 * sizeof(char) + sizeof(agenda) + *aux * sizeof(agenda);
        pessoa = pB + 5 * sizeof(int) + 60 * sizeof(char) + sizeof(agenda) + *j * sizeof(agenda);

        for(*j; *j<*qnt; (*j)++){
            if(comparaString(pessoa2->nome,pessoa->nome)){
                *aux = *j;
                 pessoa2 = pB + 5 * sizeof(int) + 60 * sizeof(char) + sizeof(agenda) + *aux * sizeof(agenda);
            }
            pessoa++;
        }

        pessoa = pB + 5 * sizeof(int) + 60 * sizeof(char) + sizeof(agenda) + *i * sizeof(agenda);
        *auxAg = *pessoa;
        *pessoa = *pessoa2;
        *pessoa2 = *auxAg;

    }
}

int *comparaString(char *str, char *str2)
{
    char *s1 = pB + 5 * sizeof(int);
    char *s2 = pB + 5 * sizeof(int) + 30 * sizeof(char);
    char *aux;

    strcpy(s1, str);
    strcpy(s2, str2);

    aux = s1;
    while(*aux){
        *aux = tolower(*aux);
        aux++;
    }

    aux = s2;
    while(*aux){
        *aux = tolower(*aux);
        aux++;
    }

    if(strcmp(s1, s2) > 0)
        return opc;

    return 0;
}
