#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

//----------Estruturas--------------

struct agenda{ //Estrutura dos dados ou registro
    char name[30];
    int num;
};
typedef struct agenda reg;

typedef struct node *avlNodePtr;
typedef avlNodePtr DicionaryType; //Estrutura dos nodos
struct node{
    reg data;
    avlNodePtr left, right;
};

struct sentinel{ //estrutura Sentinela
    avlNodePtr rootTree;
};

typedef struct sentinel sentry;

//-------Funções--------

int FB(avlNodePtr treePtr);
int Heigh(avlNodePtr treePtr);
void rotateLeft(avlNodePtr *rootPtr);
void rotateRight(avlNodePtr *rootPtr);
int balanceLeft(avlNodePtr *rootPtr);
int balanceRight(avlNodePtr *rootPtr);
int balance(avlNodePtr *rootPtr);
int Insert(avlNodePtr *rootTree, reg *newElement);
void antecessor(avlNodePtr q, avlNodePtr *r);
int remover(reg *tobeRemoved, avlNodePtr *treePtr);
void startTree(sentry *sP);
void searchT(reg *inputSearch, avlNodePtr *treePtr);
int isAVl(avlNodePtr rootPtr);
#endif // AVL_H_INCLUDED
