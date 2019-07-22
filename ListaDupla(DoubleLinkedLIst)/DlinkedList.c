#include <stdio.h>
#include <stdlib.h>
#include "DlinkedList.h"
#include "menu.h"

LS CreatList() //Aloca sentinela da lista
{
  LS L = malloc(sizeof(Sentinel));
  startList(L);
  return L;

}

int Empty(LS List) // Verifica se a lista está vazia
{
    if (List->Head == NULL)
        return 1;

    return 0;
}

void startList(LS List) //Inicializa a Lista
{
    List->Head = NULL;
    List->Last = NULL;
    List->Count = 0;
}

nodePtr NewNode() //Aloca um nodo
{
    nodePtr N = malloc(sizeof(node));
    N->Right = NULL;
    N->Left = NULL;
    return N;
}

int pushHead(LS List, unsigned int Data) //Insere na Cabeça
{
    if(Empty(List)){
        nodePtr N = NewNode();
        if(!N)
            return 0;
        N->num = Data;
        List->Head = N;
        List->Last = N;
        List->Count++;
        return 1;
    }else{
        nodePtr N = NewNode();
        if(!N)
            return 0;
        nodePtr Aux = List->Head;
        Aux->Left = N;
        N->Right = Aux;
        N->num = Data;
        List->Head = N;
        List->Count++;
        return 1;
    }
    return 0;
}

int pushLast(LS List, unsigned int Data) //Insere na ultima posição
{
    if(Empty(List)){
        nodePtr N = NewNode();
        if(!N)
            return 0;
        N->num = Data;
        List->Head = N;
        List->Last = N;
        List->Count++;
        return 1;
    }else{
        nodePtr N = NewNode();
        if(!N)
            return 0;
        nodePtr Aux = List->Last;
        Aux->Right = N;
        N->Left = Aux;
        N->num = Data;
        List->Last = N;
        List->Count++;
        return 1;
    }
    return 0;
}

int closerBeginning(int b, int e, int p) // b = Inicio, E = Fim e p = Posição
{
    b -= p;  // (b - p) + (e -p)
    e -=p;
    if ((b + e) < 0) // Resultado negativo retorna 0 pois esta mais perto do fim
        return 0;

    return 1; // Resultado 0 ou posivo retorna 1 pois esta mais perto do Inicio
}

int pushMiddLe(LS List, unsigned int Data, int position) //Insere Na posição do Meio
{
    if(!position){
        if(pushHead(List, Data))
            return 1;
        return 0;
    }

    if(position == List->Count){
        if(pushLast(List, Data))
            return 1;
        return 0;
    }

    nodePtr N = NewNode();
    if(!N)
        return 0;
    N->num = Data;
    nodePtr Aux;
    if(closerBeginning(0, List->Count, position)){ //Verifica se é mais rapido percorer do inicio para o fim
        Aux = List->Head->Right;
        for(int i = 1; i < position; i++)
            Aux = Aux->Right;
    }
    else{
        Aux = List->Last;
        for(int i = List->Count - 1; i > position; i--)
           Aux = Aux->Left;
    }
    N->Left = Aux->Left;
    N->Right = Aux;
    Aux->Left->Right = N;
    Aux->Left = N;
    List->Count++;
    return 1;
}

void Clear(LS List) //Limpa Lista
{
    if(Empty(List))
        return;

    nodePtr Aux = List->Head;
    while(Aux)
    {
        List->Head = Aux->Right;
        free(Aux);
        Aux = List->Head;
    }
    List->Last = List->Head;
    List->Count = 0;
}

void Enlist(LS List) //Lista a Lista da Cabeça para o fim ou do fim para o começo
{
    if(Empty(List)){
        printf("\nList Empty\n\nPress any key to continue\n");
        getchar();
        return;
    }
      int opt;
      nodePtr Aux;
    do{
        ClearScreen();
        printf("\n1 - In Order\n2 - Reverse Order\n0 - Back\n");
        scanf("%d", &opt);

        switch(opt){
            case 1:
                Aux = List->Head;
                printf("\nListing...\n\n");
                while(Aux){
                    printf("%d ", Aux->num);
                    Aux = Aux->Right;
                }
                pressAnyKey();
            break;

            case 2:
                Aux = List->Last;
                printf("\nListing...\n\n");
                while(Aux){
                    printf("%d ", Aux->num);
                    Aux = Aux->Left;
                }
                pressAnyKey();
            break;

            case 0:
                return;
            break;

            default:
                printf("\nInvalid Input!\n");
            break;
        }
    }while(opt);
}

unsigned int *PopTop(LS List)
{
    if(Empty(List))
        return NULL;

    nodePtr Aux = List->Head;
    List->Head = Aux->Right;
    if(Aux->Right)
        Aux->Right->Left = NULL;
    if(List->Last == Aux)
        List->Last = NULL;
    unsigned int *R = malloc(sizeof(unsigned int));
    *R = Aux->num;
    free(Aux);

    return R;
}

unsigned int *PopEnd(LS List)
{
    if(Empty(List))
        return NULL;

    nodePtr Aux = List->Last;
    List->Last = Aux->Left;
    if(Aux->Left)
        Aux->Left->Right = NULL;
    if(List->Head == Aux)
        List->Head = NULL;
    unsigned int *R = malloc(sizeof(unsigned int));
    *R = Aux->num;
    free(Aux);

    return R;
}
unsigned int *PopNumber(LS List, nodePtr Head, unsigned int toBeRemoved)
{
    if(!Head)
        return NULL;

    if(Head->num != toBeRemoved)
        return PopNumber(List, Head->Right, toBeRemoved);

    if(List->Head == Head)
        return PopTop(List);

    if(List->Last == Head)
        return PopEnd(List);

    Head->Left->Right = Head->Right;
    Head->Right->Left = Head->Left;

    unsigned int *R = malloc(sizeof(unsigned int));
    *R = Head->num;

    free(Head);
    return R;
}

int changeHead(LS List, unsigned int num)
{
    if(Empty(List))
        return 0;
    if(List->Head->num == num)
        return 0;

    nodePtr Aux = List->Head;

    while(Aux){
        if(Aux->num == num)
            break;
        Aux = Aux->Right;
    }

    if(!Aux)
        return 0;

    List->Last->Right = List->Head;
    List->Head->Left = List->Last;
    Aux->Left->Right = NULL;
    List->Last = Aux->Left;
    Aux->Left = NULL;
    List->Head = Aux;

    return 1;
}
