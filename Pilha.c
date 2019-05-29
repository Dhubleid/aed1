#include <stdio.h>
#include <stdlib.h>
#define MAX = 10;

typedef struct person{
    char name;
    int age;
}person;

typedef struct personStack{
    person persons[MAX];
    int top;
    int base;
    int limit;
}personStack;

void reset(personStack *personS)
{
    personS->persons = NULL;
    personS->top = NULL;
    personS->base = NULL;
}

int empty(personStack *personS)
{
    return personS->top == 0;
}

int full(personStack *personS)
{
    return personS->top == MAX;
}


int push(personStack *personS)
{
    if(!full(personS)){
        scanf("%[^/n]s", personS->persons[personS->top]->name);
        scanf("%d",) personS->persons[personS->top]->age;);
        personS->top++;

        return 1;
    }

    return 0;
}

int
