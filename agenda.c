#include <stdio.h>
#include <stdlib.h>

void novoContato(void *pB);
void buscaContato(void *pB);
void apagarContato(void *pB);
void listarContatos(void *pB);
void ordenaçaoInsert(void *pB);

typedef struct agenda{
    char nome[20];
    int num;
};

void *pB = NULL;
int *qnt = NULL;
int *i = NULL;
int *aux = NULL;
int *j = NULL;
agenda *pessoa = NULL;
char *auxc = NULL;


int main()
{

    int *opc;

    if( !(pB = malloc(5*sizeof(int) + 30*sizeof(char) + sizeof(agenda))) )
            exit(1);


    opc = pB;
    qnt = pB + sizeof(int);

    *qnt = 0;

    do{
       printf("1 - Novo Contato\n2 - Busca\n3- Apagar Contato\n4 - Listar Contatos\n0 - Sair\n");
       scanf("%d", aux);

       switch(*aux){

       case 1:
        novoContato(pB);
       break;

       case 2:
        buscaContato(pB);
       break;

       case 3:
        apagarContato(pB);
       break;

       case 4:
        listarContatos(pB);
       break;

       case 0:
        return 0;
       break;

       default :
        printf("\nOpcao Invalida\n");
       }

    }while(opc!=0);

    return 0;
}

void novoContato(void *pB){

    *qnt ++;

    if(*qnt == 1)
        pessoa = pB + 5*sizeof(int) + 30*sizeof(char);
        else
            pB = realloc(pB, 5*sizeof(int) + 30*sizeof(char) + *qnt * sizeof(agenda))
            pessoa = pB + 5*sizeof(int) + 30*sizeof(char) + (*qnt - 1) * sizeof(agenda);



    printf("Nome: \n");
    scanf("%[^\0]s", pessoa->nome);

    printf("Numero: \n");
    scanf("%d", pessoa->num);

}

void buscaContato(void *pB){
    Printf("Digite o nome: \n");
    scanf("%[^\0]s", auxc);

    for(*i=0; *i<qnt; (*i)++){
                pessoa = pB + 5*sizeof(int) + i*sizeof(agenda);
                printf("Nome: %s\n", pessoa->nome);
                printf("Numero: %d\n", pessoa->num);


}

void apagarContato(void *pB){}

void listarContatos(void *pB){

    if(qnt == 0)
        printf("\nAgenda Vazia\n");

        else{

            for(*i=0; *i<qnt; (*i)++){
                pessoa = pB + 5*sizeof(int) + i*sizeof(agenda);
                printf("Nome: %s\n", pessoa->nome);
                printf("Numero: %d\n", pessoa->num);
            }
        }
}


void ordenacaoBF(void *pB){}

void ordenacaoInsert(void *pB){}
}()
