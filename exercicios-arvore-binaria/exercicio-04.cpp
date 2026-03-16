
/*
4.	Comportamento de Duplicados: O que acontece no código atual se você executar add(root, 5)?
O novo valor será inserido à esquerda ou à direita?

R: O valor 5 foi inserido à direita da raiz 5, e à esquerda do nodo 8,
pois a função add começa verificando se o número é menor que a raiz para
inserir na esquerda. Caso não seja menor, automaticamente irá cair no else
de inserção na direita. Como não há tratamento para números iguais, o 5 foi
inserido à direita.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
	int valor;
	struct nodo *esq;
	struct nodo *dir;
} Nodo;

Nodo* create(int valor){
	Nodo *n = (Nodo *) malloc(sizeof(Nodo));
	n->valor = valor;
	n->esq = NULL;
	n->dir = NULL;
	return n;
}

void imprimir(Nodo *n){
	if(n==NULL){
		printf("Aborta o loop \n" );
		return;		
	}
			
	printf("Chamou o loop  da esquerda com o no: %i\n", n->valor);
	if(n->esq==NULL){
		printf(" a proxima esquerda e nula, Vai abortar, imprimir o valor e chamar o loop da direita\n ");
	}
	
	imprimir(n->esq);	
	printf("\n Valor: %d\n",n->valor);
	
	printf("Chamou o loop  da direita com o no: %i\n", n->valor);
	if(n->dir==NULL){
	    printf(" a proxima direita e nula, Vai abortar e acabou a funcao, volta pra quem esta esperando ou encerra tudo\n ");
	}
	imprimir(n->dir);
}

void add(Nodo *n, int valor) {
	if(valor < n->valor){
		if(n->esq == NULL)
			n->esq = create(valor);
		else
			add(n->esq,valor);
			
	}else{
		if(n->dir == NULL)
			n->dir = create(valor);
		else
			add(n->dir,valor);
	}
}

int main(void) {  	
	Nodo *raiz = create(5);
	
	add(raiz, 2);
	add(raiz, 1);
	add(raiz, 8);
	add(raiz, 4);
	add(raiz, 5);
	imprimir(raiz);
	
	return 0;
}
