#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arvore.h"

BstNodeP *nodeAllocator(BstNodeP *treePtr) //Alocador dos Nodos
{
    if(!(*treePtr = malloc(sizeof(struct BstNode)))){
        printf("Error allocating memory, exiting program...\n");
        exit(1);
    }
    return treePtr;
}

void searchT(agenda *inputSearch, BstNodeP *treePtr) // função de busca na arvore - retorna ponteiro
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

void insertData(agenda inptData, BstNodeP *treePtr)
{
    if(*treePtr == NULL){
        treePtr = nodeAllocator(treePtr);
        (*treePtr)->data = inptData;
         (*treePtr)->left = NULL; (*treePtr)->right = NULL;
        return;
    }

    if(compareString(inptData.name, (*treePtr)->data.name) < 0 ){
        insertData(inptData, &(*treePtr)->left);
        return;
    }

    if (compareString(inptData.name, (*treePtr)->data.name) > 0){
        insertData(inptData, &(*treePtr)->right);
    }else
        printf("Data already in the tree\n");
}

void startTree(sentinel *sentileP)
{
    sentileP->rootTree = NULL;
    sentileP->countNodes = 0;
}

void antecessor(BstNodeP q, BstNodeP *r)
{
    BstNodeP aux;
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

void remover(agenda tobeRemoved, BstNodeP *treePtr)
{
    BstNodeP aux;

    if(*treePtr == NULL){
        printf("Error: Data not Found");

        return;
    }

    if (strcmp(tobeRemoved.name,(*treePtr)->data.name) < 0){
        remover(tobeRemoved, &(*treePtr)->left);
        return;
    }

    if (strcmp(tobeRemoved.name,(*treePtr)->data.name) > 0){
        remover(tobeRemoved, &(*treePtr)->right);
        return;
    }


    if((*treePtr)->right == NULL){
        aux = *treePtr;
        *treePtr = (*treePtr)->left;
        free(aux);
        return;
    }

    if((*treePtr)->left != NULL){
        antecessor(*treePtr, &(*treePtr)->left);
        return;
    }

    aux = *treePtr;
    *treePtr = (*treePtr)->right;
    free(aux);
}

int compareString(char *str, char *str2)
{
    char *s1 = malloc(30 * sizeof(char));
    char *s2 = malloc(30 * sizeof(char));
    char *aux1;

    strcpy(s1, str);
    strcpy(s2, str2);

    aux1 = s1;
    while(*aux1){
        *aux1 = tolower(*aux1);
        aux1++;
    }

    aux1 = s2;
    while(*aux1){
        *aux1 = tolower(*aux1);
        aux1++;
    }

    if(strcmp(s1, s2) > 0)
        return 1;

    if(strcmp(s1, s2) < 0)
        return -1;
    free(s1);
    free(s2);
    return 0;
}
