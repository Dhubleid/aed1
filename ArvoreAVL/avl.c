#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl.h"

int FB(avlNodePtr treePtr)
{
    if(treePtr == NULL)
        return 0;

    return Heigh(treePtr->left) - Heigh(treePtr->right);
}

int Heigh(avlNodePtr treePtr)
{
    int countLeft, countRight;

    if (treePtr == NULL)
        return 0;
    countLeft = Heigh(treePtr->left);
    countRight = Heigh(treePtr->right);

    if(countLeft > countRight)
        return countLeft + 1;
    else
        return countRight + 1;
}

void rotateLeft(avlNodePtr *rootPtr)
{
    avlNodePtr auxPtr;
    auxPtr = (*rootPtr)->right;
    (*rootPtr)->right = auxPtr->left;
    auxPtr->left = (*rootPtr);
    (*rootPtr) = auxPtr;
}

void rotateRight(avlNodePtr *rootPtr)
{
    avlNodePtr auxPtr;
    auxPtr = (*rootPtr)->left;
    (*rootPtr)->left = auxPtr->right;
    auxPtr->right = (*rootPtr);
    (*rootPtr) = auxPtr;
}

int balanceLeft(avlNodePtr *rootPtr)
{
    int flagB = FB((*rootPtr)->left);
    if(flagB > 0){
        rotateRight(rootPtr);
        return 1;
    }
    else if(flagB < 0){
            rotateLeft( &((*rootPtr)->left) );
            rotateRight(rootPtr);
            return 1;
    }

    return 0;
}

int balanceRight(avlNodePtr *rootPtr)
{
    int flagB = FB((*rootPtr)->right);
    if(flagB < 0){
        rotateLeft(rootPtr);
        return 1;
    }
    else if(flagB > 0){
        rotateRight( &((*rootPtr)->right) );
        rotateLeft(rootPtr);
        return 1;
    }

    return 0;
}

int balance(avlNodePtr *rootPtr)
{
    int flag = FB(*rootPtr);
    if( flag > 1)
        return balanceLeft(rootPtr);
    else if (flag < -1)
        return balanceRight(rootPtr);
    else
        return 0;
}

int Insert(avlNodePtr *rootTree, reg *newElement)
{
    if(*rootTree == NULL){

        *rootTree =  malloc(sizeof(struct node));
        (*rootTree)->data = *newElement;
        (*rootTree)->left = NULL;
        (*rootTree)->right = NULL;

        return 1;
    }
    else if (strcasecmp((*rootTree)->data.name, newElement->name) > 0) {
        if(Insert(&(*rootTree)->left, newElement)) {
            balance(rootTree);
            return 1;
        }
    }

    else if (strcasecmp((*rootTree)->data.name, newElement->name) < 0){
        if(Insert(&(*rootTree)->right, newElement)) {
            balance(rootTree);
            return 1;
        }
    }
    return 0;
}

void antecessor(avlNodePtr q, avlNodePtr *r)
{
    avlNodePtr aux;
    if((*r)->right != NULL)
    {
        antecessor(q, &(*r)->right);
        return;
    }
    q->data = (*r)->data;
    aux = *r;
    *r = (*r)->left;
    free(aux);
}

int remover(reg *tobeRemoved, avlNodePtr *treePtr)
{
    avlNodePtr aux;

    if(*treePtr == NULL){
        printf("Error: Data not Found");
        return 0;
    }

    if (strcmp(tobeRemoved->name,(*treePtr)->data.name) < 0){
        if(remover(tobeRemoved, &(*treePtr)->left))
            balance(treePtr);
        return 1;
    }

    if (strcmp(tobeRemoved->name,(*treePtr)->data.name) > 0){
        if(remover(tobeRemoved, &(*treePtr)->right))
            balance(treePtr);
        return 1;
    }

    if((*treePtr)->right == NULL){ //Direita é nulo ou Direita e Esquerda Nulo
        aux = *treePtr;
        *treePtr = (*treePtr)->left;
        free(aux);
        balance(treePtr);
        return 1;
    }

    if((*treePtr)->left != NULL){ // Tem os Dois Filhos
        antecessor(*treePtr, &(*treePtr)->left);
        balance(treePtr);
        return 1;
    }

    aux = *treePtr; // Direita não é Nulo e a Esquerda Sim
    *treePtr = (*treePtr)->right;
    free(aux);

    balance(treePtr);

    return 1;
}

void searchT(reg *inputSearch, avlNodePtr *treePtr)
{
    if(*treePtr == NULL){
        printf("Data isn't on tree\n");
        return;
    }

    if(strcmp(inputSearch->name, (*treePtr)->data.name) < 0 ){
        searchT(inputSearch, &(*treePtr)->left);
        return;
    }

    if (strcmp(inputSearch->name, (*treePtr)->data.name) > 0){
        searchT(inputSearch, &(*treePtr)->right);
    }else
        *inputSearch = (*treePtr)->data;
}

void startTree(sentry *sP)
{
    sP->rootTree = NULL;
}

int isAVl(avlNodePtr rootPtr)
{
    int flag;

    if(rootPtr == NULL)
        return 1;

    if(!isAVl(rootPtr->left))
        return 0;

    if(!isAVl(rootPtr->right))
        return 0;

    flag = FB(rootPtr);

    if((flag > 1) || (flag < -1))
        return 0;

    return 1;
}

