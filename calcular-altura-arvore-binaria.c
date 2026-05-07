#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nodo{
	int valor;
	struct nodo *esq;
	struct nodo *dir;
	int altura;
} Nodo;

int valorRaiz;
bool sair = false;
int op;
Nodo *raiz = NULL;

void menu(){
    if(raiz){
	    printf("Valor da Raiz: %d", raiz->valor);
	    printf("\n");
	}			
	printf("01 - Inserir Nodo\n");	
	printf("02 - Altura \n");
	printf("03 - Imprimir\n");
	printf("04 - Sair do Sistema\n");
	printf("\nDigite uma Opcao: ");
	
}

void sairDoSistema(){
	printf("Saindo do sistema...\n");
	sair = true;
}

Nodo *create(int valor){
	Nodo *n = (Nodo*)malloc(sizeof(Nodo));
	n->valor = valor;
	n->esq = NULL;
	n->dir = NULL;
	n->altura = -1;
	return n;
}

void imprimir(Nodo *n){
	if(valorRaiz == NULL) {
		printf("\nA arvore esta vazia!\n");
		return;
	}
	
	if(n==NULL){
		return;
	}
	
	imprimir(n->esq);
	printf("\n%d", n->valor);
	imprimir(n->dir);	
}


void add(Nodo *n, int valor){
	if(valor < n-> valor){
		if(n->esq == NULL){
			n->esq = create(valor);
		}else{
			add(n->esq,valor);
		}	
	}else{		
		if(n->dir == NULL){
			n->dir = create(valor);
		}else{
			add(n->dir,valor);
		}
	}
}

void insere(){
	if(raiz == NULL) {
		printf("\nCrie a raiz antes de inserir um nodo!\n");
		printf("\nDigite o valor da raiz: ");
		scanf("%d", &valorRaiz);
		
		raiz = create(valorRaiz);
		printf("\nRaiz %d criada com sucesso!\n", raiz->valor);
		
		system("pause");
		return;
	}
	
	int valor;
	printf("Digite o valor do nodo: ");
	scanf("%d", &valor);
	add(raiz, valor);
	
	printf("\nNodo %d inserido com sucesso!\n", valor);
	system("pause");
}

int altura(Nodo *n){
	if(n == NULL){
		return -1;
	}
	
	int alturaEsquerda = altura(n->esq);
	printf("Valor da Esquerda: %d", alturaEsquerda);
	printf("\n");
	
	int alturaDireita  = altura(n->dir);
	printf("Valor da Direita: %d", alturaDireita);
	printf("\n");
	
	if(alturaEsquerda > alturaDireita){
		return alturaEsquerda + 1;
	}else{
		return alturaDireita + 1;
	}		
}

int main(){
	
	while(!sair){
		system("CLS");
		menu();
		scanf("%d", &op);
		
		switch(op){
			case 1:
				insere();
				break;
			case 2:
				printf("\nAltura: %d\n", altura(raiz));
				system("pause");
				break;
			case 3:
				imprimir(raiz);
				printf("\n");
				system("pause");
				break;
			case 4:
				sairDoSistema();
				break;		
			default:
				printf("\nOpcao invalida!\n");
				system("pause");
		}
	}
	return 0;
}
