// PILHA - LIFO

#include <stdio.h>
#include <stdlib.h>

typedef struct tempAluno {
	int id;
	char nome[100];
	struct tempAluno *prox;
} Aluno;

Aluno *topo = NULL;

void adicionarAluno() {	
	Aluno *alunos = (Aluno*)malloc(sizeof(Aluno));
	
	if (!alunos) {
		printf("\nNao foi possivel alocar na memoria");
		return;
	}
	
	printf("\nID do aluno: ");
	scanf("%d", &alunos->id);
	
	printf("\nNome do aluno: ");
	getchar();
	fgets(alunos->nome, 100, stdin);
	
	if (!topo) {
		alunos->prox = NULL;
	} else {
		alunos->prox = topo;	
	}
	
	topo = alunos;
	
	system("CLS");
	printf("\nAluno adicionado a pilha");
}

void removerAluno() {
	system("CLS");
	
	if (!topo) {
		printf("\nA pilha esta vazia");
		return;
	}
	
	Aluno *aux = topo;
	topo = aux->prox;
	free(aux);

	printf("\nAluno removido da pilha");
}

void imprimirPilha() {
	Aluno *aux = topo;
	
	system("CLS");
	
	printf("\n---- Dados dos Alunos ----");

    while (aux != NULL) {
        printf("\nID: %d", aux->id);
        printf("\nNome: %s", aux->nome);

        if (!aux->prox) {
            printf("Proximo: NULL\n");
        } else {
            printf("Proximo: %d\n", aux->prox->id);
        }

        printf("-------------------------\n");

        aux = aux->prox;
    }
	
	printf("\n--------------------------");
}

void liberarPilha() {
	Aluno *aux = topo;
	Aluno *temp;
	
	while (aux) {
		temp = aux;
		aux = aux->prox;
		free(temp);
	}
	
	topo = NULL;
}

void menu() {
	printf("\n\n---- Pilha de Alunos ----");
	printf("\n-- Selecione uma Opcao --\n");
	printf("\n1- Adicionar Aluno");
	printf("\n2- Remover Aluno");
	printf("\n3- Imprimir Pilha");
	printf("\n0- Sair\n");
	printf("\n-------------------------\n\n");
}


int main () {
	int opcao = -1;
	
	while (opcao != 0) {	
		menu();
		scanf("%d", &opcao);
		
		switch (opcao) {
			case 1:
				adicionarAluno();
				break;
			case 2:
				removerAluno();
				break;
			case 3:
				imprimirPilha();
				break;
			case 0:
				printf("\nSaindo...");
				break;
			default:
				printf("\nOpcao invalida");		
		}
	}
	
	liberarPilha();
	
	return 0;
}
