#include <stdio.h>
#include <stdlib.h>

void novoContato(void *pB);
void buscaContato(void *pB);
void apagarContato(void *pB);
void listarContatos(void *pB);
void ordenaçãoBF(void *pB);
void ordenaçaoInsert(void *pB);

typedef struct agenda{

int indx;
char nome[20];
int num;
}agen;

int *qnt = NULL;
int *num = NULL;
char *nome = NULL;

int main(){
    void *pB = NULL;

    int *aux = NULL;



    pB = malloc(sizeof(int)*2);
        if(pB == NULL){
            exit(1);
        }
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

    pB = realloc(buffer, (sizeof(int)*2+(sizeof(char)*20 + sizeof(int))*(*qnt));

    nome = pB + sizeof(int)*2+(sizeof(char)*20 + sizeof(int))*(*qnt-1);
    num = pB + sizeof(int)*2+(sizeof(char)*20 + sizeof(int))*(*qnt-1) + sizeof(char)*20;

    printf("Nome: \n");
    scanf("%s20", nome);

    printf("Numero: \n");
    scanf("%d", numero);

}

void buscaContato(void *pB){

}

void apagarContato(void *pB){}

void listarContatos(void *pB){

if(qnt==0){
printf("\nAgenda Vazia\n");
break;
}
    else{

for(int i=0;i<qnt;i++){

nome = pB + sizeof(int)*2+(sizeof(char)*20 + sizeof(int))*(*qnt-1);
num = pB + sizeof(int)*2+(sizeof(char)*20 + sizeof(int))*(*qnt-1) + sizeof(char)*20;

}



}

void ordenacaoBF(void *pB){}

void ordenacaoInsert(void *pB){}
}()
