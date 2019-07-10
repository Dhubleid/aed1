#include <stdio.h>
#include <stdlib.h>
#include "RN.h"
#include "listagem.h"


void preOrder(NodePtr *treePtr)
{

    if(!*treePtr)
        return;

    printf("\n\tNome: %s\n",(*treePtr)->data.name);
    printf("\tNumber: %d\n", (*treePtr)->data.num);

    preOrder(&(*treePtr)->left);

    preOrder(&(*treePtr)->right);

}


void center(NodePtr *treePtr)
{
    if(!*treePtr)
        return;

    center(&(*treePtr)->left);

    printf("\n\tNome: %s\n",(*treePtr)->data.name);
    printf("\tNumber: %d\n", (*treePtr)->data.num);

    center(&(*treePtr)->right);

}

void postOrder(NodePtr *treePtr)
{
    if(!*treePtr)
        return;


    postOrder(&(*treePtr)->right);

    printf("\n\tNome: %s\n",(*treePtr)->data.name);
    printf("\tNumber: %d\n", (*treePtr)->data.num);

    postOrder(&(*treePtr)->left);
}
