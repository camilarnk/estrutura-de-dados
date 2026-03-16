#include <stdio.h>
#include <stdlib.h>

/*
1.	Adicione ao main um novo nó com o valor 10 e conecte-o como filho à direita do nodo8. -- feito
2.	Escreva um printf que imprima o valor do nodo4 acessando-o a partir do nodo5 (ex: nodo5->esq->dir->valor). -- feito
3.	Crie uma função void imprimir(Nodo *n) que receba um nó e imprima seu valor. Use-a no main para imprimir o nodo5. -- feito
4.	Escreva um if que verifique se o nodo8 possui um filho à esquerda e imprima "Vazio" caso seja NULL. -- feito
5.  Mude o valor do nodo1 para 7 sem criar um novo nó, apenas acessando o ponteiro existente. -- feito
*/

typedef struct nodo{
	int valor;
	struct nodo *esq;
	struct nodo *dir;
} Nodo;

Nodo* create(int valor){
	Nodo *n = (Nodo*)malloc(sizeof(Nodo));
	n->valor = valor;
	n->esq = NULL;
	n->dir = NULL;
	return n;
}

// 3.	Crie uma função void imprimir(Nodo *n) que receba um nó e imprima seu valor. Use-a no main para imprimir o nodo5.
void imprimir(Nodo *n) {
	printf("\nValor do nodo%d: %d", n->valor, n->valor);
}

int main() {
	Nodo *nodo5 = create(5);
	Nodo *nodo2 = create(2);
	Nodo *nodo1 = create(1);
	Nodo *nodo8 = create(8);
	Nodo *nodo4 = create(4);
		
	nodo5->esq = nodo2;
	nodo2->esq = nodo1;
	nodo5->dir = nodo8;
	nodo2->dir = nodo4;
	
	// 1.	Adicione ao main um novo nó com o valor 10 e conecte-o como filho à direita do nodo8.
	Nodo *nodo10 = create(10);
	nodo8->dir = nodo10;
	
	// 2.	Escreva um printf que imprima o valor do nodo4 acessando-o a partir do nodo5 (ex: nodo5->esq->dir->valor).
	printf("\nValor do nodo4: %d", nodo5->esq->dir->valor);
	
	imprimir(nodo5);
	
	// 4.	Escreva um if que verifique se o nodo8 possui um filho à esquerda e imprima "Vazio" caso seja NULL.
	if (nodo8->esq) {
		printf("\nNodo8 possui um filho à esquerda. Valor: %d", nodo8->esq->valor);
	} else {
		printf("\nVazio");
	}
	
	// 5.  Mude o valor do nodo1 para 7 sem criar um novo nó, apenas acessando o ponteiro existente.
	nodo1->valor = 7;
	printf("\nValor do nodo1: %d", nodo1->valor);
	
	return 0;
}
