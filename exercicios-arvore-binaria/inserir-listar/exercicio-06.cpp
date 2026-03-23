
/*
6.	Inversão de Ordem: Modifique a função imprimir para que ela exiba os números em ordem decrescente.
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
			
	printf("Chamou o loop  da direita com o no: %i\n", n->valor);
	if(n->dir==NULL){
		printf(" a proxima direita e nula, Vai abortar, imprimir o valor e chamar o loop da esquerda\n ");
	}
	
	imprimir(n->dir);	
	printf("\n Valor: %d\n",n->valor);
	
	printf("Chamou o loop  da esquerda com o no: %i\n", n->valor);
	if(n->esq==NULL){
	    printf(" a proxima esquerda e nula, Vai abortar e acabou a funcao, volta pra quem esta esperando ou encerra tudo\n ");
	}
	imprimir(n->esq);
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
	imprimir(raiz);
	
	return 0;
}
