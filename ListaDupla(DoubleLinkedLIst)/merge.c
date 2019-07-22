#include <stdio.h>
#include <stdlib.h>
#include "DlinkedList.h"
#include "merge.h"

nodePtr Merge(nodePtr First, nodePtr Second)
{
    if(!First)
        return Second;
    if(!Second)
        return First;
    if(First->num < Second->num){
        First->Right = Merge(First->Right, Second);
        First->Right->Left = First;
        First->Left = NULL;
        return First;
    }else{
        Second->Right = Merge(First, Second->Right);
        Second->Right->Left = Second;
        Second->Left = NULL;
        return Second;
    }
}
nodePtr MergeSort(nodePtr Head, nodePtr *LastRef)
{
    if(!Head || !Head->Right)
        return Head;

    nodePtr Second = split(Head);

    Head = MergeSort(Head,LastRef);
    Second = MergeSort(Second,LastRef);

    if((*LastRef)->num < Head->num)
        (*LastRef) = Head;

    if((*LastRef)->num < Second->num)
        (*LastRef) = Second;

    return Merge(Head, Second);
}

nodePtr split(nodePtr Head)
{
    nodePtr Fast = Head, Slow = Head;

    while(Fast->Right && Fast->Right->Right){
        Fast = Fast->Right->Right;
        Slow = Slow->Right;
    }

    nodePtr Aux = Slow->Right;
    Slow->Right = NULL;

    return Aux;
}
