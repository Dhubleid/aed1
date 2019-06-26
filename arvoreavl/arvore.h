#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

//Estruturas
struct agenda{ //Estrutura Registro ou Dados
    char name[30]; //name será usado como chave
    int num;
};
typedef struct agenda agenda;

typedef struct BstNode *BstNodeP; //Esturtura dos nodos da Arvore
struct BstNode {
    agenda data;
    BstNodeP left;
    BstNodeP right;
};

struct sentinel{ //Estrutura sentinela com o nó raiz e informações
    BstNodeP rootTree; //Raiz
    int countNodes; // Quantidades de nós
    //char complete; // String está Completa?("Yes" e "No" ou "Empty")
};
typedef struct sentinel sentinel;

//Funções da Arvore

void searchT(agenda *agenda, BstNodeP *treePtr);

void insertData(agenda inptData, BstNodeP *treePtr);

BstNodeP *nodeAllocator(BstNodeP *treePtr);

void startTree(sentinel *sentinelP);

void remover(agenda tobeRemoved, BstNodeP *treePtr);

void antecessor(BstNodeP q, BstNodeP *r);

int compareString(char *str, char *str2);

#endif // ARVORE_H_INCLUDED
