#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RN.h"

char BLACK = 'B';
char RED = 'R';

NodePtr grandparent(NodePtr treePtr)
{
    if((treePtr != NULL) && (treePtr->parent != NULL))
        return treePtr->parent->parent;
    else
        return NULL;
}

NodePtr uncle(NodePtr treePtr)
{
    if(treePtr == NULL)
        return NULL;
    else
        return brother(treePtr->parent);
}

NodePtr brother(NodePtr treePtr)
{
    if((treePtr == NULL) || (treePtr->parent == NULL) )
        return NULL;
    else if(treePtr == treePtr->parent->left)
            return treePtr->parent->right;
        else
            return treePtr->parent->left;
}

NodePtr rotateLeft(NodePtr rootPtr, NodePtr treePtr)
{
    NodePtr r = treePtr->right;

    if(treePtr == NULL)
        return rootPtr;

    if(rootPtr == treePtr)
        rootPtr = r;
    else if(treePtr == treePtr->parent->left)
            treePtr->parent->left = r;
        else
            treePtr->parent->right = r;

    treePtr->right = r->left;

    if(r->left != NULL)
        r->left->parent = treePtr;

    r->left = treePtr;
    r->parent = treePtr->parent;
    treePtr->parent = r;

    return rootPtr;
}

NodePtr rotateRight(NodePtr rootPtr, NodePtr treePtr)
{
    NodePtr l = treePtr->left;

    if(treePtr == NULL)
        return rootPtr;

    if(rootPtr == treePtr)
        rootPtr = l;

    else if(treePtr == treePtr->parent->right)
            treePtr->parent->right = l;
        else
            treePtr->parent->left = l;

    treePtr->left = l->right;

    if(l->left != NULL)
        l->right->parent = treePtr;

    l->right = treePtr;
    l->parent = treePtr->parent;
    treePtr->parent = l;

    return rootPtr;
}

void rotateLeftRR(NodePtr *x)
{
    NodePtr y;
    y = *x;
    *x = (*x)->left;
    (*x)->parent = y->parent;
    y->left = (*x)->right;

    if(y->left)
        y->left->parent = y;

    (*x)->right = y;
    y->parent = *x;
}

void rotateRightRR(NodePtr *x)
{
    NodePtr y;
    y = *x;
    *x = (*x)->right;
    (*x)->parent = y->parent;
    y->right = (*x)->left;

    if(y->right)
        y->right->parent = y;

    (*x)->left = y;
    y->parent = *x;
}



char verifyColor(NodePtr treePtr)
{
    if(treePtr == NULL)
        return BLACK;
    else
        return treePtr->color;
}

NodePtr insertCase1(NodePtr rootPtr, NodePtr treePtr)
{
    if(treePtr->parent == NULL){
        treePtr->color = BLACK;
        return rootPtr;
    }
    else
        return insertCase2(rootPtr, treePtr);
}

NodePtr insertCase2(NodePtr rootTree, NodePtr treePtr)
{
    if(treePtr->color == BLACK)
        return rootTree;
    else
       return insertCase3(rootTree, treePtr);
}

NodePtr insertCase3(NodePtr rootTree, NodePtr treePtr)
{
    if(verifyColor(uncle(treePtr)) == RED){
        treePtr->parent->color = BLACK;
        uncle(treePtr)->color = BLACK;
        grandparent(treePtr)->color = RED;
        return insertCase1(rootTree, grandparent(treePtr));
    }else
        return insertCase4(rootTree, treePtr);
}

NodePtr insertCase4(NodePtr rootPtr, NodePtr treePtr)
{
    if((treePtr == treePtr->parent->left) && (treePtr->parent == grandparent(treePtr)->right)){
        rootPtr = rotateRight(rootPtr, treePtr->parent);
        treePtr = treePtr->right;
    }else if((treePtr == treePtr->parent->right) && (treePtr->parent == grandparent(treePtr)->left)){
            rootPtr = rotateLeft(rootPtr, treePtr->parent);
            treePtr = treePtr->left;
    }
    return insertCase5(rootPtr, treePtr);
}

NodePtr insertCase5(NodePtr rootPtr, NodePtr treePtr)
{
    treePtr->parent->color = BLACK;
    grandparent(treePtr)->color = RED;
    if((treePtr == treePtr->parent->left) && (treePtr->parent == grandparent(treePtr)->left))
       rootPtr = rotateRight(rootPtr, grandparent(treePtr));
    else
        rootPtr = rotateLeft(rootPtr, grandparent(treePtr));

    return rootPtr;
}

NodePtr newNode(reg newData)
{
    NodePtr newPtr;
    newPtr = malloc(sizeof(struct node));
    newPtr->data = newData;
    newPtr->color = RED;
    newPtr->left = NULL;
    newPtr->right = NULL;
    newPtr->parent = NULL;

    return newPtr;
}

NodePtr InsertElement(NodePtr rootTree, reg newElement)
{
    NodePtr newPtr = newNode(newElement);

    if(rootTree == NULL){
        newPtr->color = BLACK;
        return newPtr;
    }

    NodePtr aux = rootTree;

    while(1){
        if(!strcmp(newPtr->data.name, aux->data.name)){
            free(newPtr);
            return rootTree;
        }

        else if(strcmp(newPtr->data.name,aux->data.name) < 0){
            if(aux->left == NULL){
                aux->left = newPtr;
                newPtr->parent = aux;
                return insertCase1(rootTree, newPtr);
            }

            else{
                aux = aux->left;
            }
        }

        else {
            if (aux->right == NULL){
                aux->right = newPtr;
                newPtr->parent = aux;
                return insertCase1(rootTree, newPtr);
            }

            else{
                aux = aux->right;
            }
        }
    }
}

NodePtr smallerRight(NodePtr rootTree)
{
    NodePtr aux;

    aux = rootTree->right;

    if(aux == NULL){
        return NULL;
    }
    else{
        while(aux->left != NULL){
            aux = aux->left;
        }
    return aux;
    }
}

NodePtr remover(char *name, NodePtr rootTree)
{
    NodePtr node;
    NodePtr aux;
    NodePtr big;

    char colorAux;

   node = SearchElement(name, rootTree);

    if(rootTree == NULL || node == NULL){
        return rootTree;
    }

    colorAux = node->color;

    if(node->left == NULL){
        aux = node->right;
        transplant(&rootTree,node, node->right);
    }

    else if(node->right == NULL){
        aux = node->left;
        transplant(&rootTree, node, node->left);
    }

    else{
        big = smallerRight(node);
        colorAux = big->color;
        aux = big->right;

        if(big->parent == node){
            if(aux != NULL){
                aux->parent = big;
            }
        }

        else{
            transplant(&rootTree, big, big->right);
            big->right = node->right;
            big->right->parent = big;
        }

        transplant(&rootTree, node, big);
        big->left = node->left;
        big->left->parent = big;
        big->color = node->color;
    }

    if(colorAux == BLACK){
        if(aux!= NULL){
           fixBalance(&rootTree, aux);
        }
    }

    free(node);

    return rootTree;
}

NodePtr fixBalance(NodePtr *rootTree, NodePtr treePtr)
{
    NodePtr aux;
    while((treePtr != *rootTree) && (verifyColor(treePtr) == BLACK)){
        if(treePtr == treePtr->parent->right){
            aux = treePtr->parent->right;

            if(verifyColor(aux) == RED){
                aux->color = BLACK;
                treePtr->parent->color = RED;
                rotateLeftRR(&treePtr->parent);
                aux = treePtr->parent->right;
                continue;
            }

            if(verifyColor(aux->right) == BLACK && verifyColor(aux->right) == BLACK){
                aux->color = RED;
                treePtr = treePtr->parent;
                continue;
            }

            else if(verifyColor(aux->right) == RED){
                aux->right->color = BLACK;
                aux->color = RED;
                rotateRightRR(&aux);
                aux = aux->parent->right;
                continue;
            }
            aux->color = treePtr->parent->color;
            treePtr->parent->color = BLACK;
            aux->right->color = BLACK;
            rotateLeftRR(&treePtr->parent);
            treePtr = *rootTree;
        }

        else{
            aux = treePtr->parent->right;

            if(verifyColor(aux) == RED){
                aux->color = BLACK;
                treePtr->parent->color = RED;
                rotateRightRR(&treePtr->parent);
                aux = treePtr->parent->right;
                continue;
            }

            if(verifyColor(aux->right) == BLACK && verifyColor(aux->right) == BLACK){
                aux->color = RED;
                treePtr = treePtr->parent;
                continue;
            }

            else if(verifyColor(aux->right) == RED){
                aux->right->color = BLACK;
                aux->color = RED;
                rotateLeftRR(&aux);
                aux = aux->parent->right;
                continue;
            }
            aux->color = treePtr->parent->color;
            treePtr->parent->color = BLACK;
            aux->right->color = BLACK;
            rotateRightRR(&treePtr->parent);
            treePtr = *rootTree;
        }
    }

    if(treePtr != NULL){
        treePtr->color = BLACK;
    }
    return *rootTree;
}

NodePtr transplant(NodePtr *rootTree, NodePtr treePtr, NodePtr nodeAux){
    if(treePtr->parent == NULL){
        *rootTree = nodeAux;
    }

    else if(treePtr == treePtr->parent->left){
        treePtr->parent->left = nodeAux;
    }

    else{
        treePtr->parent->right = nodeAux;
    }

    if(nodeAux == NULL){
        return *rootTree;
    }
    else{
        nodeAux->parent = treePtr->parent;
        return *rootTree;
    }
}

NodePtr SearchElement(char *name, NodePtr rootTree){
    if(rootTree == NULL){
        return NULL;
    }
    if (strcmp(name, rootTree->data.name) < 0){
        return SearchElement(name, rootTree->left);
    }
    if(strcmp(name, rootTree->data.name) > 0){
        return SearchElement(name, rootTree->right);
    }
    return rootTree;
}

void startTree(sentry *sP)
{
    sP->treePtr = NULL;
}
