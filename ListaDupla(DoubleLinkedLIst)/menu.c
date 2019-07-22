#include <stdio.h>
#include <stdlib.h>
#include "DlinkedList.h"
#include "menu.h"
#include "merge.h"

void ClearScreen(){ //Limpa a tela de acordo com o sistema operacional
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}

void Menu(LS List)
{   int opt;
    int num;
    nodePtr Aux;
    do{
        ClearScreen();
        printf("\n1 - New Element\n2 - Remove\n3 - Sort\n4 - Clear List\n5 - Enlist\n6 - Change Head\n7 - Search\n0 - Exit\n");
        scanf("%d",&opt);
        getchar();
        switch(opt){

            case 1:
                menuPush(List);
            break;

            case 2:
                menuPop(List);
            break;

            case 3:
                List->Head = MergeSort(List->Head, &List->Last);
            break;

            case 4:
                Clear(List);
            break;

            case 5:
                Enlist(List);
            break;

            case 6:
                printf("\nEnter the number to be the new Head\n");
                scanf("%d", &num);
                if(changeHead(List, num))
                    printf("\nHead has been changed.\n");
                else
                    printf("\nNot possible\n");
                pressAnyKey();
            break;

            case 7:
                printf("\nEnter the number to Search\n");
                scanf("%d", &num);
                if((Aux = Search(List->Head, num)))
                    printf("\n\tNumber found on the list\n\t");
                else
                    printf("\nNumber not found\n");

                pressAnyKey();
            break;

            case 0:
                exit(1);
            break;

            default:
                printf("\nInvalid Input\n");
                pressAnyKey();
            break;
        }
    }while(opt);
}

void menuPush(LS List)
{
    unsigned int newNum;
    int opt;
    int position;
    do{
        ClearScreen();
        printf("\n1 - Insertion on top\n2 - Insertion on End\n3 - Insertion on Determined Position\n0 - Back\n");
        scanf("%d",&opt);

        switch(opt){
            case 1:
                printf("\nEnter the new Element:\n");
                scanf("%u",&newNum);
                if(pushHead(List, newNum))
                    printf("\nNew Element Inserted!\n");
                else
                    printf("\nWas Not Possible to Insert!\n");
                pressAnyKey();
            break;

            case 2:
                printf("\nEnter the new Element:\n");
                scanf("%u",&newNum);
                if(pushLast(List, newNum))
                    printf("\nNew Element Inserted!\n");
                else
                    printf("\nWas Not Possible to Insert!\n");
                pressAnyKey();
            break;

            case 3:
                printf("\nEnter the Position from 0 to %d\n", List->Count);
                scanf("%d",&position);
                if(position < 0 || position > List->Count){
                    printf("\nInvalid Position!\n");
                    break;
                }
                printf("\nEnter the new Element\n");
                scanf("%u", &newNum);
                if(pushMiddLe(List, newNum, position))
                    printf("\nNew Element Inserted!\n");
                else
                    printf("\nWas Not Possible to Insert!\n");
                pressAnyKey();
            break;

            case 0:
                return;
            break;

            default:
                printf("\nInvalid Input\n");
            break;
        }
    }while(opt);
}

void menuPop(LS List)
{
    unsigned int *toBeRemoved;
    int opt;

    do{
        ClearScreen();
        printf("\n1 - Remove from Top\n2 - Remove from End\n3 - Remove by Element\n0 - Back\n");
        scanf("%d",&opt);
        switch(opt){
            case 1:
                toBeRemoved = PopTop(List);
                if(toBeRemoved)
                    printf("\nNumber %u has been successfully removed\n", *toBeRemoved);
                else
                    printf("\nEmpty List\n");

                pressAnyKey();
            break;

            case 2:
                toBeRemoved = PopEnd(List);
                if(toBeRemoved)
                    printf("\nNumber %u has been successfully removed\n", *toBeRemoved);
                else
                    printf("\nEmpty List\n");

                pressAnyKey();
            break;

            case 3:
                printf("\nEnter the number to delete:\n");
                toBeRemoved = malloc(sizeof(unsigned int));
                scanf("%u", toBeRemoved);
                toBeRemoved = PopNumber(List, List->Head, *toBeRemoved);
                if(toBeRemoved)
                    printf("\nNumber %u has been successfully removed\n", *toBeRemoved);
                else
                    printf("\nNumber not found on the list\n");

                free(toBeRemoved);
                pressAnyKey();
            break;

            case 0:
                return;
            break;

            default:
                printf("\nInvalid Input\n");
                pressAnyKey();
            break;
        }
    }while(opt);

    free(toBeRemoved);
}

void pressAnyKey()
{
    printf("\nPress any key to continue.%c\n", getchar());
    getchar();
}
