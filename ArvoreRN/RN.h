#ifndef RN_H_INCLUDED
#define RN_H_INCLUDED

//----------Estruturas--------------

extern char BLACK, RED;

struct agenda{ //Estrutura dos dados ou registro
    char name[30];
    int num;
};
typedef struct agenda reg;

typedef struct node *NodePtr;
typedef NodePtr DicionaryType; //Estrutura dos treePtrdos
struct node{
    reg data;
    char color;
    NodePtr parent;
    NodePtr left, right;
};

struct sentinel{ //estrutura Sentinela
    NodePtr treePtr;
};

typedef struct sentinel sentry;

//-------Funções--------

NodePtr grandparent(NodePtr treePtr);
NodePtr uncle(NodePtr treePtr);
NodePtr brother(NodePtr treePtr);

NodePtr insertCase1(NodePtr rootPtr, NodePtr treePtr);
NodePtr insertCase2(NodePtr rootPtr, NodePtr treePtr);
NodePtr insertCase3(NodePtr rootPtr, NodePtr treePtr);
NodePtr insertCase4(NodePtr rootPtr, NodePtr treePtr);
NodePtr insertCase5(NodePtr rootPtr, NodePtr treePtr);

NodePtr rotateLeft(NodePtr rootPtr, NodePtr treePtr);
NodePtr rotateRight(NodePtr rootPtr, NodePtr treePtr);
void rotateLeftRR(NodePtr *x);
void rotateRightRR(NodePtr *x);

NodePtr newtreePtrde(reg newData);
NodePtr InsertElement(NodePtr rootTree, reg newElement);

NodePtr fixBalance(NodePtr *rootTree, NodePtr treePtr);
NodePtr smallerRight(NodePtr rootTree);
NodePtr transplant(NodePtr *rootTree, NodePtr treePtr, NodePtr nodeAux);
NodePtr remover(char *name, NodePtr rootTree);

NodePtr SearchElement(char *name, NodePtr rootTree);

void startTree(sentry *sP);

#endif // RN_H_INCLUDED
