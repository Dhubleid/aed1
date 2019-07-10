#include <stdio.h>
#include <stdlib.h>
#include "RN.h"
#include "listagem.h"

void clear(){
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}

int main()
{
    sentry S;
    startTree(&S);
    reg aux;
    NodePtr treePtr;

    int option;

    do{
        printf("\nRB Tree\n\n1 - Add Data\n2 - Remove Data\n3 - Search Data\n4 - List PreOrder"
               "\n5 - List center\n6 - List Post order\n8 - Clear Screen\n0 - Exit\n" );
        scanf("%d", &option);
        getchar();

        switch(option){

            case 1:
                printf("Enter the name:\n");
                scanf("%[^\n]s", aux.name);
                getchar();
                printf("Enter the number\n");
                scanf("%d", &aux.num);
                S.treePtr = InsertElement(S.treePtr, aux);

            break;

            case 2:
                printf("Enter the name:\n");
                scanf("%[^\n]s", aux.name);
                getchar();
                aux.num = 0;
                S.treePtr = remover(aux.name, S.treePtr);

            break;

            case 3:
                printf("Enter the name:\n");
                scanf("%[^\n]s", aux.name);
                getchar();
                aux.num = 0;
                treePtr = SearchElement(aux.name, S.treePtr);
                if(treePtr)
                    printf("\n\tData found:\n\tName: %s\n\tNumber: %d\n", treePtr->data.name, treePtr->data.num);
                else
                    printf("\n\tData not found!\n");
            break;

            case 4:
                if(S.treePtr){
                    printf("\tListing:\n");
                    preOrder(&S.treePtr);
                }else
                    printf("Tree Empty\n");
            break;

            case 5:
                if(S.treePtr){
                    printf("\tListing:\n");
                    center(&S.treePtr);
                }else
                    printf("Tree Empty\n");
            break;

            case 6:
                if(S.treePtr){
                    printf("\tListing:\n");
                    postOrder(&S.treePtr);
                }else
                    printf("Tree Empty\n");
            break;

            case 8:
                clear();
            break;

            case 0:
                exit(1);
            break;

            default:
                printf("Input Invalid\n");
            break;
        }
    }while(option);

}
