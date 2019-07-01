#include <stdio.h>
#include <stdlib.h>
#include "avl.h"
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
    avlNodePtr *treePtr = &S.rootTree;

    int option;

    do{
        printf("\nAVL Tree\n\n1 - Add Data\n2 - Remove Data\n3 - Search Data\n4 - List PreOrder"
               "\n5 - List center\n6 - List Post order\n7 - Test AVL\n8 - Clear Screen\n0 - Exit\n" );
        scanf("%d", &option);
        getchar();

        switch(option){

            case 1:
                printf("Enter the name:\n");
                scanf("%[^\n]s", aux.name);
                getchar();
                printf("Enter the number\n");
                scanf("%d", &aux.num);
                treePtr = &S.rootTree;
                if (Insert(treePtr, &aux))
                    printf("\nData was correctly Inserted\n");
                else
                    printf("\nData already in the Tree\n");

            break;

            case 2:
                printf("Enter the name:\n");
                scanf("%[^\n]s", aux.name);
                getchar();
                aux.num = 0;
                treePtr = &S.rootTree;
                if(remover(&aux, treePtr))
                    printf("\nData has been removed\n");
            break;

            case 3:
                printf("Enter the name:\n");
                scanf("%[^\n]s", aux.name);
                getchar();
                aux.num = 0;
                treePtr = &S.rootTree;
                searchT(&aux, treePtr);
                if(aux.num)
                    printf("\n\tData found:\n\tName: %s\n\tNumber: %d\n", aux.name, aux.num);
            break;

            case 4:
                if(*treePtr){
                    printf("\tListing:\n");
                    preOrder(treePtr);
                }else
                    printf("Tree Empty\n");
            break;

            case 5:
                if(*treePtr){
                    printf("\tListing:\n");
                    center(treePtr);
                }else
                    printf("Tree Empty\n");
            break;

            case 6:
                if(*treePtr){
                    printf("\tListing:\n");
                    postOrder(treePtr);
                }else
                    printf("Tree Empty\n");
            break;

            case 7:
                if(isAVl(S.rootTree))
                   printf("\n\tYES\n");
                else
                    printf("\n\tNO\n");
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
