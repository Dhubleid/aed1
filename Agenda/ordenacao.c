#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "agenb.h"
#include "ordenacao.h"

void quickSort(int left, int right)
{
    *i = left;
    *j = right;

    auxAg = pB + 5 * sizeof(int) + 60 * sizeof(char) + sizeof(agenda) + ((left + right)/2) * sizeof(agenda);
    strcpy(auxc, auxAg->nome);

    auxAg = pB + 5 *sizeof(int) + 60 * sizeof(char);

    pessoa = pB + 5 * sizeof(int) + 60 * sizeof(char) + sizeof(agenda) + *i * sizeof(agenda);
    pessoa2 = pB + 5 * sizeof(int) + 60 * sizeof(char) + sizeof(agenda) + *j * sizeof(agenda);

    do{
        while((comparaString(pessoa->nome, auxc)) < 0 && *i <= right){
            (*i)++;
            pessoa++;
        }
        while((comparaString(pessoa2->nome, auxc)) > 0 && *j >= left){
            (*j)--;
            pessoa2--;
        }

        if(*i <= *j){
            *auxAg = *pessoa;
            *pessoa = *pessoa2;
            *pessoa2 = *auxAg;
            (*i)++;
            (*j)--;
            pessoa++;
            pessoa2--;
        }
    }while(*i <= *j);

    if(left < *j)
        quickSort(left, *j);

    if(*i < right)
        quickSort(*i, right);
}


void insertionSort()
{
    for(*i=1; *i<*qnt; (*i)++){

        pessoa2 = pB + 5 * sizeof(int) + 60 * sizeof(char);

        pessoa = pB + 5 * sizeof(int) + 60 * sizeof(char) + sizeof(agenda) + *i * sizeof(agenda);

        *pessoa2 = *pessoa;

        *j = *i - 1;

        pessoa = pB + 5 * sizeof(int) + 60 * sizeof(char) + sizeof(agenda) + *j * sizeof(agenda);

        while(*j >= 0 && (comparaString(pessoa->nome, pessoa2->nome) > 0)){
            *(pessoa + 1) = *pessoa;
            (*j)--;
            pessoa--;
        }
       *(pessoa + 1) = *pessoa2;
    }
}

void selectSort()
{

    for(*i=0; *i<*qnt-1; (*i)++){

        *aux = *i;
        *j = *i + 1;

        pessoa2 = pB + 5 * sizeof(int) + 60 * sizeof(char) + sizeof(agenda) + *aux * sizeof(agenda);
        pessoa = pB + 5 * sizeof(int) + 60 * sizeof(char) + sizeof(agenda) + *j * sizeof(agenda);

        for(*j=*j; *j<*qnt; (*j)++){
            if((comparaString(pessoa2->nome,pessoa->nome)) > 0){
                *aux = *j;
                 pessoa2 = pB + 5 * sizeof(int) + 60 * sizeof(char) + sizeof(agenda) + *aux * sizeof(agenda);
            }
            pessoa++;
        }

        pessoa = pB + 5 * sizeof(int) + 60 * sizeof(char) + sizeof(agenda) + *i * sizeof(agenda);
        *auxAg = *pessoa;
        *pessoa = *pessoa2;
        *pessoa2 = *auxAg;

    }
}

int comparaString(char *str, char *str2)
{
    char *s1 = pB + 5 * sizeof(int);
    char *s2 = pB + 5 * sizeof(int) + 30 * sizeof(char);
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

    return 0;
}

void bubbleSort()
{
   for (*i = 0; *i<*qnt-1; (*i)++){
        *aux = 0;
        *j=0;
        pessoa = pB + 5 * sizeof(int) + 60 * sizeof(char) + sizeof(agenda) + *j * sizeof(agenda);

        while(*j < *qnt-*i-1){
            if((comparaString(pessoa->nome,(pessoa + 1)->nome)) > 0){
                *auxAg = *pessoa;
                *pessoa = *(pessoa + 1);
                *(pessoa + 1 ) = *auxAg;
                *aux=1;
            }
            pessoa++;
            (*j)++;
        }

    if(!(*aux))
        break;
    }
}



