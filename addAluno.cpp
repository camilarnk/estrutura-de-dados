#include <stdio.h>
#include <stdlib.h>

typedef struct temp_aluno {
	int id;
	char nome[100];
	struct temp_aluno *prox;
} Aluno;

Aluno *primeiroLista = NULL;

void addPrimeiro() {
	Aluno *alunos = (Aluno*)malloc(sizeof(Aluno));
	
	printf("\nID do aluno: ");
	scanf("%d", &alunos->id);
	
	printf("\nNome do aluno:");
	getchar();
	fgets(alunos->nome, 100, stdin);
	
	alunos->prox = primeiroLista;
	primeiroLista = alunos;
}

void addUltimo() {
	Aluno *alunos = (Aluno*) malloc(sizeof(Aluno));
	
	printf("\nID do aluno: ");
	scanf("%d", &alunos->id);
	
	printf("\nNome do aluno:");
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

void imprime(Aluno *aux) {
	printf("\n---- Dados dos Alunos ----\n");

    while (aux) {
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

int main() {
	
	printf("\n---- Inserindo no inicio----\n");
    addPrimeiro();
    imprime(primeiroLista);
    
    printf("\n---- Inserindo no final----\n");
    addUltimo();
    imprime(primeiroLista);
    
	return 0;
}
