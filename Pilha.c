#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct person{ // Dados usados na pilha
    char name[30];
    int age;
}person;

typedef struct personStack{ // Estrutura da Pilha
    person persons[MAX];
    int top;
    int base;
    int limit;
}personStack;

void clear(personStack *personS);  // Limpa a pilha atribuindo uma pilha vazia
void reset(personStack *personS); // Reseta a pilha
int empty(personStack *personS); // Verifica se a pilha está vazia
int full(personStack *personS); // Verifica se a pilha está cheia
int push(personStack *personS, person *newPerson); // Insere elemento na pilha
person *pop(personStack *personS); //Remove da pilha e retorna um ponteiro para o elemento removido

int main()
{
    personStack stackP;
    person *personAux;
    person personAux2;
    char name[30];
    int popCount;
    int opc;

    reset(&stackP);

   do{
    printf("Stack:\n0 - Insert person\n1 - Delete Person from top\n2 - Delete person by name\n3 - List the stack\n4 - Clear Stack\n5 - exit\n");
    scanf("%d", &opc);
    getchar();
    switch(opc){

        case(0):
            printf("Insert the name:\n ");
            scanf("%[^\n]s", &personAux2.name);

            printf("Insert the age: \n");
            scanf("%d", &personAux2.age);

            push(&stackP, &personAux2);
        break;

        case(1):
            personAux = pop(&stackP);
        break;

        case(2):

            popCount=0;
            printf("Type the name: ");
            scanf("%[^\n]s", name);

            while(!empty(&stackP)){
                personAux = pop(&stackP);
                popCount++;
                if(!strcmp(name, personAux->name)){
                   while(popCount>1){
                        personAux++;
                        push(&stackP, personAux);
                        popCount--;
                   }
                    break;
                }
            }
            if(empty(&stackP)){

                printf("Name not found!\n");

                while(popCount){
                    push(&stackP, personAux);
                    personAux++;
                    popCount--;
                }
            }
        break;

        case(3):
            popCount = 0;
            printf("Listing:\n");

            while (!empty(&stackP)){
                personAux = pop(&stackP);
                popCount++;
                printf("Name: %s\nAge: %d\n", personAux->name, personAux->age);
            }

            while(popCount){
                push(&stackP, personAux);
                personAux++;
                popCount--;
            }
        break;

        case(4):
            clear(&stackP);
        break;

        case(5):
            exit(1);
        break;

        default:
            printf("\n Invalid Input:\n");
        break;

    }
   }while(opc != 5);
    return 0;
}
void clear(personStack *personS) // Limpa a pilha atribuindo uma pilha vazia
{
    personStack emptyS;
    reset(&emptyS);
    *personS = emptyS;
}

void reset(personStack *personS) // Reseta a pilha
{
    personS->top = 0;
    personS->base = 0;
    personS->limit = MAX;
}

int empty(personStack *personS) // Verifica se a pilha está vazia
{
    return personS->top == 0;
}

int full(personStack *personS) // Verifica se a pilha está cheia
{
    return personS->top == MAX;
}


int push(personStack *personS, person *newPerson) // Insere elemento na pilha
{
    if(!full(personS)){
        personS->persons[personS->top] = *newPerson;
        personS->top++;

        return 1;
    }

    return 0;
}
person *pop(personStack *personS) //Remove da pilha e retorna um ponteiro para o elemento removido
{
    if(empty(personS))
        return NULL;
    personS->top--;
    return &personS->persons[personS->top];
}
