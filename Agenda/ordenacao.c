#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "agenb.h"
#include "ordenacao.h"


void insertionSort()
{
    for(*i=1; *i<*qnt; (*i)++){

        pessoa2 = pB + 5 * sizeof(int) + 60 * sizeof(char);

        pessoa = pB + 5 * sizeof(int) + 60 * sizeof(char) + sizeof(agenda) + *i * sizeof(agenda);

        *pessoa2 = *pessoa;

        *j = *i - 1;

        pessoa = pB + 5 * sizeof(int) + 60 * sizeof(char) + sizeof(agenda) + *j * sizeof(agenda);

        while(*j >= 0 && (comparaString(pessoa->nome, pessoa2->nome))){
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
            if(comparaString(pessoa2->nome,pessoa->nome)){
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

int *comparaString(char *str, char *str2)
{
    char *s1 = pB + 5 * sizeof(int);
    char *s2 = pB + 5 * sizeof(int) + 30 * sizeof(char);
    char *aux;

    strcpy(s1, str);
    strcpy(s2, str2);

    aux = s1;
    while(*aux){
        *aux = tolower(*aux);
        aux++;
    }

    aux = s2;
    while(*aux){
        *aux = tolower(*aux);
        aux++;
    }

    if(strcmp(s1, s2) > 0)
        return opc;

    return 0;
}
