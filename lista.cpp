#include <stdio.h>
#include <stdlib.h>

typedef struct temp_aluno {
	int id;
	char nome[100];
	struct temp_aluno *prox;
} Aluno;

Aluno *primeiroLista = NULL;

void addPrimeiro();
void addUltimo();
void removerInicio();
void imprimir();
void liberarLista();

void menu() {
	printf("\n\n---- Gerenciando Alunos ----\n");
	printf("\n1- Inserir no Inicio");
	printf("\n2- Inserior no Final");
	printf("\n3- Imprimir Lista de Alunos");
	printf("\n4- Remover do Inicio");
	printf("\n0- Sair\n\n");
}

int main() {
	
	int opcao = -1;
	
	while (opcao != 0) {	
		
		menu();
		scanf("%d", &opcao);
		
		if (opcao == 1) {
			addPrimeiro();
		} else if (opcao == 2) {
			addUltimo();
		} else if (opcao == 3) {
			imprimir();
		} else if (opcao == 4) {
			removerInicio();
		} else if (opcao == 0) {
			printf("\nEncerrando...");
		} else {
			printf("\nOpcao invalida.");
		}
	}
	
    liberarLista();
    
	return 0;
}

void addPrimeiro() {
	Aluno *alunos = (Aluno*)malloc(sizeof(Aluno));
	
	if (!alunos) {
		printf("\nFalha ao tentar alocar memoria");
		return;
	}
	
	printf("\nID do aluno: ");
	scanf("%d", &alunos->id);
	
	printf("\nNome do aluno: ");
	getchar();
	fgets(alunos->nome, 100, stdin);
	
	alunos->prox = primeiroLista;
	primeiroLista = alunos;
}

void addUltimo() {
	Aluno *alunos = (Aluno*) malloc(sizeof(Aluno));
	
	if (!alunos) {
		printf("\nFalha ao tentar alocar memoria");
		return;
	}
	
	printf("\nID do aluno: ");
	scanf("%d", &alunos->id);
	
	printf("\nNome do aluno: ");
	getchar();
	fgets(alunos->nome, 100, stdin);
	
	alunos->prox = NULL;
	
	if (!primeiroLista) {
		primeiroLista = alunos;
	} else {
		Aluno *aux = primeiroLista;	
		
		while(aux->prox) {
			aux = aux->prox;
		}
		
		aux->prox = alunos;
	}
}

void removerInicio() {
	if (!primeiroLista) {
		printf("\nA lista esta vazia");
		return;
	}
	
	Aluno *aux = primeiroLista;
	primeiroLista = aux->prox;
	free(aux);
	
	printf("\nAluno removido da lista");
}

void imprimir() {
	Aluno *aux = primeiroLista;
	printf("\n---- Dados dos Alunos ----\n");

    while (aux != NULL) {
        printf("\nID: %d", aux->id);
        printf("\nNome: %s", aux->nome);

        if (!aux->prox) {
            printf("Proximo: NULL\n");
        } else {
            printf("Proximo: %d\n", aux->prox->id);
        }

        printf("--------------------------\n");

        aux = aux->prox;
    }
}

void liberarLista() {
	
	Aluno *aux = primeiroLista;
	Aluno *temp;
	
	while (aux) {
		temp = aux;
		aux = aux->prox;
		free(temp);
	}
	
	primeiroLista = NULL;
}
