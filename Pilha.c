#include<stdio.h>
#include<string.h>
const int MAX = 10;

struct Aluno
{
int ra;
char nome[50];
};

struct Pilha{
struct Aluno alunos[MAX];
int topo;
int base;
int limite;
};

void Empty(){
return pilha->topo == 0;
}

void Reset(){
pilha->topo = 0;
pilha->base = 0;
pilha->limite = MAX;
}

void Full(){
return pilha->topo == MAX;
}



int main() {
	int x;
	
	
	do {
	printf ("digite 1 para resetar a pilha");
	printf ("digite 2 para esvaziar a pilha");
	printf ("digite 3 para  a pilha");
	printf ("digite 4 para  a pilha");
	printf ("digite 0 para sair");
	scanf("%d",& x);
	if (x==1) Reset();
	if (x==2) Empty();
	if (x==3) Full();
	if (x==4) ();
	if (x==5) ();
	}
	while (x<0);
	
	
	
  return 0;
}
