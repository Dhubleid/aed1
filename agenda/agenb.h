#ifndef AGENB_H_INCLUDED
#define AGENB_H_INCLUDED

struct agenda{
    char nome[30];
    int num;
};

typedef struct agenda agenda;


extern void *pB;

//ponteiros abaixo em ordem que estao amazenados no buffer

extern int *qnt; // Guarda o numero de srructs(pessoas) da agenda
extern int *i; // variavel auxiliar
extern int *j;// variavel auxiliar
extern int *opc;// variavel para as opcoes do switch
extern int *aux;

extern char *auxc;// string auxiliar

//ponteiros para as structs(pessoas) da agenda

extern agenda *pessoa;
extern agenda *pessoa2;
extern agenda *auxAg;

//fuçôes

void novoContato();
agenda *buscaContato();
void apagarContato();
void listarContatos();
void realoca();
void aponta(); // função para ajustar os ponteiros após os reallocs e malloc
void enderecarPessoa(agenda *p, int *i);

#endif // AGENB_H_INCLUDED
