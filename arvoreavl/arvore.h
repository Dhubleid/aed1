#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED


struct agenda{
    char nome[30];
    int num;
};

typedef struct agenda agenda;

struct BstNode {
    agenda data;
    agenda *left;
    agenda *right;
};

typedef struct BstNode BstNode;


void searchT(agenda *agenda, BstNode *rootPtr);

void insertData(agenda *inptData, BstNode *treePtr);

void nodeAllocator(BstNode *treePtr);

void startTree(BstNode *treePtr)

#endif // ARVORE_H_INCLUDED
