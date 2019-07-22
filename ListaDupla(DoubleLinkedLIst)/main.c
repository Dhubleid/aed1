#include <stdio.h>
#include <stdlib.h>
#include "DlinkedList.h"
#include "menu.h"

int main()
{
    LS List = CreatList();

    Menu(List);

    Clear(List);

    free(List);
    return 0;
}

