#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

void nodeAllocator(BstNode *treePtr) //Alocador dos Nodos
{
    if(!(*treePtr = malloc(sizeof(BstNode)))){
        printf("Error allocating memory, exiting program...\n")
        exit(1);
    }
}

void searchT(agenda *inputSearch, BstNode *treePtr) // função de busca na arvore - retorna ponteiro
{
    if(treePtr == NULL){
        printf("Dados não encontrados\n");
        return;
    }

    if(strcmp(agenda->nome, treePtr->data->nome) < 0 ){
        searchT(agenda, &treePtr->left);
        return;
    }

    if (strcmp(agenda->nome, treePtr->data->nome) > 0){
        searchT(agenda->nome, &treePtr->right);
    }else
        *inputSearch = treePtr->data;
}

void insertData(agenda *inptData, BstNode *treePtr)
{
    if(*treePtr == NULL){
        nodeAllocator(treePtr);
        treePtr->data = *inptData;
        treePtr->left = NULL; treePtr->right = NULL;
        return;
    }

    if(strcmp(agenda->nome, treePtr->data->nome) < 0 ){
        insertData(agenda, &treePtr->left);
        return;
    }

    if (strcmp(agenda->nome, treePtr->data->nome) > 0){
        insertData(agenda->nome, &treePtr->right);
    }else
        printf("Data already in the tree\n");
}

void startTree(BstNode *treePtr)
{
    *treePtr = NULL;
}
