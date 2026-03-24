/*

----

1. Se chamarmos rem(raiz, 10) em uma árvore onde o nodo 10 não possui filhos,
qual trecho do código será executado e qual será o estado do ponteiro do pai?

R: O trecho do código executado será o if(filho != NULL){...}, que remove um nodo
folha (sem filhos). O estado do ponteiro pai (20) será: esquerda null e direita = 40.

----

2. O que acontece se tentarmos remover o valor que está na raiz da árvore usando
essa função rem?

R: Ao tentar passar remover(raiz, raiz) ocorrerá um erro de compilação no programa.
Ao tentar remover passando o valor da raiz diretamente, remover(raiz, 50), nada foi
modificado na impressão da árvore.

----

3. Desenhe uma subárvore onde o nodo 20 tem o filho 15 à esquerda e nenhum à
direita. Se removermos o 20, quem ocupará o lugar dele na estrutura do pai?

R: resposta em exercicio-03.PNG.

----

4. O que o código atual faz se tentarmos remover um nodo que possui tanto filho à
esquerda quanto à direita?

R: O nodo nao sera removido, pois a função 'remover' nao verifica atualmente se um
nodo possui mais que um filho. O valor assim nao entrará em nenhuma das condicionais
e sera ignorado na tentativa de remoçao.

----

5. Se percorrermos toda a árvore e o valor não for encontrado (filho == NULL), o
que o código imprime?

R: Ao tentar remover um valor inexistente, houve uma falha no codigo e nada
foi impresso devido a um erro de acesso a memoria invalida.

----

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
	int valor;
	struct nodo *esq;
	struct nodo *dir;
} Nodo;

Nodo *create(int valor);
void add(Nodo *n, int valor);
void remover(Nodo *n, int valor);
void imprimir(Nodo *n);
 
int main () {
	
	Nodo *raiz = create(50);
	
	add(raiz, 20);
	add(raiz, 10);
	add(raiz, 80);
	add(raiz, 40);
	
	printf("\n\n antes de remover o pai\n\n\n");
	imprimir(raiz);
	
	remover(raiz, 50);
	
	printf("\n\n depois de remover o pai\n\n\n");
	imprimir(raiz);
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

}

void imprimir(Nodo *n) {
	if(n == NULL) {
		printf("Aborta o loop \n" );
		return;		
	}
			
	//printf("Chamou o loop  da esquerda com o no: %i\n", n->valor);
	if(n->esq == NULL) {
	   // printf(" a proxima esquerda e nula, Vai abortar, imprimir o valor e chamar o loop da direita\n ");
	}
	imprimir(n->esq);	
	
	printf("\n Valor: %d\n",n->valor); // imprime o nó da vez
	
	//printf("Chamou o loop  da direita com o no: %i\n", n->valor);
	if(n->dir == NULL) {
	   // printf(" a proxima direita e nula, Vai abortar e acabou a função, volta pra quem esta esperando ou encerra tudo\n ");
	}
	imprimir(n->dir);
}
