
/*

7.	Busca de Valor: Crie uma função int existe(Nodo *n, int valor) que retorne 1 se o valor
estiver na árvore e 0 se não estiver, seguindo a mesma lógica de navegação da função add.

R: 

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
	int valor;
	struct nodo *esq;
	struct nodo *dir;
} Nodo;

Nodo* create(int valor) {
	Nodo *n = (Nodo*)malloc(sizeof(Nodo));
	n->valor = valor;
	n->esq = NULL;
	n->dir = NULL;
	return n;
}

void imprimir(Nodo *n) {
	if(n==NULL) {
		printf("Aborta o loop \n" );
		return;		
	}		
	printf("Chamou o loop  da esquerda com o no: %i\n", n->valor);
	
	if(n->esq==NULL) {
	    printf(" a proxima esquerda e nula, Vai abortar, imprimir o valor e chamar o loop da direita\n ");
	}
	imprimir(n->esq);
	
	printf("\n Valor: %d\n",n->valor);
	
	printf("Chamou o loop  da direita com o no: %i\n", n->valor);
	if(n->dir==NULL){
	    printf(" a proxima direita e nula, Vai abortar e acabou a função, volta pra quem esta esperando ou encerra tudo\n ");
	}
	imprimir(n->dir);
}

void add(Nodo *n, int valor) {
	if(valor < n->valor) {
		if(n->esq == NULL)
			n->esq = create(valor);
		else
			add(n->esq,valor);
			
	} else {
		if(n->dir == NULL)
			n->dir = create(valor);
		else
			add(n->dir,valor);
	}
}

int existe(Nodo *n, int valor) {
	
	if(n == NULL)
		return 0;
	
	if(n->valor == valor)
		return 1;
	
	if(valor < n->valor) {
		return existe(n->esq, valor);	
	} else {
		return existe(n->dir, valor);
	}	
}

int main(void) {  	
	Nodo *raiz = create(5);
	
	add(raiz,2);
	add(raiz,1);
	add(raiz,8);
	add(raiz,4);	
//	imprimir(raiz);

	int numeroEncontrado = existe(raiz, 2);

	if(numeroEncontrado == 1) {
		printf("\nNumero encontrado na arvore");
	} else {
		printf("\nNumero nao encontrado na arvore");
	}

  	return 0;
}

