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




#endif // ARVORE_H_INCLUDED
