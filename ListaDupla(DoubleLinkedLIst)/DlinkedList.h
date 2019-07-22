#ifndef DLINKEDLIST_H_INCLUDED
#define DLINKEDLIST_H_INCLUDED

typedef struct node *nodePtr;

struct node{  //Estrutura do nodo
    unsigned int num;
    nodePtr Left, Right;
};
typedef struct node node;

struct ListSentinel{ //Estrutura sentinela da lista
    nodePtr Head;
    nodePtr Last;
    unsigned int Count;
};
typedef struct ListSentinel Sentinel;
typedef Sentinel *LS;

LS CreatList();
void startList(LS List);
int Empty(LS List);
nodePtr NewNode();
int pushHead(LS List, unsigned int Data);
int pushLast(LS List, unsigned int Data);
int pushMiddLe(LS List, unsigned int Data, int position);
void Clear (LS List);
void Enlist(LS LIst);
unsigned int *PopTop(LS List);
unsigned int *PopEnd(LS List);
unsigned int *PopNumber(LS List, nodePtr Head, unsigned int toBeRemoved);
int changeHead(LS List, unsigned int num);
nodePtr Search(nodePtr Head, unsigned int numS);

#endif // DLINKEDLIST_H_INCLUDED
