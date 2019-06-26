#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include "listagem.h"

int main()
{
    sentinel S;
    startTree(&S);
    agenda aux;
    BstNodeP *treePtr = &S.rootTree;

    int option;

    do{
        printf("\nBinary Search Tree\n\n1 - Add Data\n2 - Remove Data\n3 - Search Data\n4 - List PreOrder"
               "\n5 - List center\n6 - List Post order\n0 - Exit\n" );
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
                insertData(aux, treePtr);
                S.countNodes++;
            break;

            case 2:
                printf("Enter the name:\n");
                scanf("%[^\n]s", aux.name);
                getchar();
                aux.num = 0;
                treePtr = &S.rootTree;
                remover(aux, treePtr);
                if(S.countNodes)
                    S.countNodes--;
            break;

            case 3:
                printf("Enter the name:\n");
                scanf("%[^\n]s", aux.name);
                getchar();
                aux.num = 0;
                treePtr = &S.rootTree;
                searchT(&aux, treePtr);
                if(aux.num)
                    printf("Data found:\nName: %s\nNumber: %d", aux.name, aux.num);
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

            case 0:
                exit(1);
            break;

            default:
                printf("Input Invalid\n");
            break;
        }
    }while(option);

}
