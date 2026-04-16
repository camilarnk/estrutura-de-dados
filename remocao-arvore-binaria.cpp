/*
Remoção em árvore binária

Situação 1: Nó Folha: um nó que não possui filhos, pai aponta p/ null;
Situação 2: Nó com apenas 1 filho, pai aponta p/ este filho;
Situação 3: Nó com 2 filhos
		(o nó é substituído pelo nodo mais à direita do seu nó esquerdo
		ou pelo nó mais à esquerda do seu nó direito).

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
	int valor;
	struct nodo *esq;
	struct nodo *dir;
	// a estrutura para esse cenario deve ser apenas essa. um nodo *inferior estaria errado
} Nodo;

Nodo *create(int valor);
void add(Nodo *n, int valor);
void remover(Nodo *n, int valor);
void imprimir(Nodo *n);
 
int main () {
	
	return 0;
}

Nodo *create(int valor){
	Nodo *n = (Nodo *) malloc(sizeof(Nodo));
	n->valor = valor;
	n->esq = NULL;
	n->dir = NULL;
	return n;
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

void remover(Nodo *n, int valor) {
	Nodo *filho = n;
	Nodo *pai;
	
	do {
		pai = filho;		
		if(valor < filho->valor) {
			filho = filho->esq;
		} else if(valor > filho->valor) {
			filho = filho->dir;
		}
	} while(filho != NULL && filho->valor != valor); // se percorreu a árvore inteira e nenhum elemento igual foi encontrado
	
	// identificando um nó folha (sem filhos)
	if(filho != NULL) {		
		if(filho->esq == NULL && filho->dir == NULL) {
			if(pai->esq == filho) {
				pai->esq = NULL;
			} else if(pai->dir == filho) {
				pai->dir = NULL;
			}
		}
	}
	
	// identificando nó com apenas um filho	
	if(filho->esq != NULL && filho->dir == NULL) { // filho à esquerda
		if(pai->esq == filho) { // verificando se o pai está do lado esquerdo
			pai->esq = filho->esq; 
		} else if(pai->dir == filho) { // verificando se o pai está do lado direito
			pai->dir = filho->dir;
		}
	}
	
	if(filho->dir != NULL && filho->esq == NULL) { // filho à direita
		if(pai->esq == filho) { // verificando se o pai está do lado esquerdo
			pai->esq = filho->dir;
		} else if(pai->dir == filho) { // verificando se o pai está do lado direito
			pai->dir = filho->dir;
		}
	}
	
	// identificando nó com dois filhos
	if(filho->esq != NULL && filho->dir != NULL) { // os dois lados estao preenchidos
		Nodo *paiSucessor = filho;
		Nodo *sucessor = filho->dir; // começa verificando pela direita
		
		while(sucessor->esq != NULL) { // seguir ate o elemento mais à esquerda possivel
			paiSucessor = sucessor;
			sucessor = sucessor->esq;
		}
		
		filho->valor = sucessor->valor; // 1. substitui o valor do nodo a apagar pelo valor do sucessor
		
		// 2. ajusta os ponteiros para remover o nodo sucessor original
		if(paiSucessor == filho) { // se o sucessor for o filho direto da direita
			filho->dir = sucessor->dir;
		} else { // se o sucessor estiver no fundo à esquerda 
			paiSucessor->esq = sucessor->dir;
		}
		
		free(sucessor); // libera memoria do nodo removido
	}

}

void imprimir(Nodo *n) {
	if(n == NULL) {
		printf("Aborta o loop \n" );
		return;		
	}
	imprimir(n->esq);	
	printf("\n Valor: %d\n",n->valor); // imprime o nó da vez
	imprimir(n->dir);
}
