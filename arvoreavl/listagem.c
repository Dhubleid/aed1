#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include "listagem.h"


void preOrder(BstNodeP *treePtr)
{

    if(!*treePtr)
        return;

    printf("\n\tNome: %s\n",(*treePtr)->data.name);
    printf("\tNumber: %d\n", (*treePtr)->data.num);

    preOrder(&(*treePtr)->left);

    preOrder(&(*treePtr)->right);

}


void center(BstNodeP *treePtr)
{
    if(!*treePtr)
        return;

    center(&(*treePtr)->left);

    printf("\n\tNome: %s\n",(*treePtr)->data.name);
    printf("\tNumber: %d\n", (*treePtr)->data.num);

    center(&(*treePtr)->right);

}

void postOrder(BstNodeP *treePtr)
{
    if(!*treePtr)
        return;


    postOrder(&(*treePtr)->right);

    printf("\n\tNome: %s\n",(*treePtr)->data.name);
    printf("\tNumber: %d\n", (*treePtr)->data.num);

    postOrder(&(*treePtr)->left);
}
