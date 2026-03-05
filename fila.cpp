// FILA - FIFO

#include <stdio.h>
#include <stdlib.h>

typedef struct tempAluno {
	int id;
	char nome[100];
	struct tempAluno *prox;
} Aluno;

Aluno *inicio = NULL;
Aluno *fim = NULL;

void adicionarAlunoFila();
void removerAlunoFila();
void imprimirFila();
void liberarFila();
void menu();

int main() {

	int opcao = -1;
	
	while (opcao != 0) {
		menu();
		scanf("%d", &opcao);
		
		switch (opcao) {
			case 1:
				adicionarAlunoFila();
				break;
			case 2:
				removerAlunoFila();
				break;
			case 3:
				imprimirFila();
				break;
			case 0:
				printf("\nEncerrando...");
				break;
			default:
				printf("\nOpcao invalida");
		}
	}
	
	liberarFila();
	
	return 0;
}

void adicionarAlunoFila() {
	
	system("CLS");
	
	Aluno *aluno = (Aluno*)malloc(sizeof(Aluno));
	
	if (!aluno) {
		printf("\nFalha ao tentar alocar memoria");
		return;
	}
	
	printf("\nID do aluno: ");
	scanf("%d", &aluno->id);
	
	printf("\nNome do aluno: ");
	getchar();
	fgets(aluno->nome, 100, stdin);
	
	if (!inicio) {
		inicio = aluno;		
	} else {
		fim->prox = aluno;
	}
	
	fim = aluno;
	aluno->prox = NULL;
	
	printf("\nAluno adicionado a fila");
}

void removerAlunoFila() {

	system("CLS");
	
	if (!inicio) {
		printf("\nA fila esta vazia");
		return;
	}
	
	Aluno *aux = inicio;
	inicio = aux->prox;
	free(aux);
	
	printf("\nAluno removido da fila");
}

void imprimirFila() {
	
	system("CLS");
	
	if (!inicio) {
		printf("\nA fila esta vazia");
		return;
	}
	
	Aluno *aux = inicio;
	
	printf("\n------------ Fila de alunos ------------\n");
	
	while (aux) {
		
		printf("\nID: %d \nNome: %s", aux->id, aux->nome);
		
		if (aux->prox) {
			printf("Proximo: %d - %s\n", aux->prox->id, aux->prox->nome);
		} else {
			printf("Proximo: NULL\n");
		}
		
		aux = aux->prox;
	}
	
	printf("\n----------------------------------------\n");
}

void liberarFila() {	
	
	Aluno *aux = inicio;
	Aluno *temp;
	
	while (aux) {
		temp = aux;
		aux = temp->prox;
		free(temp);
	}
	
	inicio = NULL;
	fim = NULL;
}

void menu() {
	
	printf("\n\n------------ Menu de Alunos ------------\n");
	printf("\nSelecione uma opcao\n");
	printf("\n1 - Adicionar aluno na fila");
	printf("\n2 - Remover aluno da fila");
	printf("\n3 - Listar fila");
	printf("\n0 - Sair\n\n");
}

