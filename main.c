#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo TNodo;
typedef struct descritor Tdescritor;
typedef struct dados Tdados;

struct nodo {
	Tdados *dados;
	TNodo *proximo;
};

struct descritor {
	TNodo* first;
	TNodo* last;
};

struct dados {
	int numero;
	char nome[10];
};

Tdescritor* criaLista() {
	Tdescritor* descritor;
	descritor = (Tdescritor*)malloc(sizeof(Tdescritor));
	descritor->first = NULL;
	descritor->last = NULL;
	return descritor;
}

void insereFim(Tdescritor* descritor, Tdados* dados) {
	TNodo *nodoaux = (TNodo*)malloc(sizeof(TNodo));
	
	nodoaux->dados = dados;
	nodoaux->proximo = NULL;
	if(descritor == NULL) {
		printf("Fila Inexistente - Crie a Fila Primeiro");
		return;
	}
	//se a lista estiver vazia
	if(descritor->first == NULL) {
		descritor->first = nodoaux;
		descritor->last = nodoaux;
	}
	else {
		descritor->last->proximo = nodoaux;
		descritor->last = nodoaux;
	}	
}

Tdados* insereDados(int numero, char nome[]) {
	Tdados* dados;
	dados = (Tdados*) malloc(sizeof(Tdados));
	dados->numero = numero;
	strcpy(dados->nome, nome);
	return dados;
}

void removeInicio(Tdescritor* lista){
	if(lista == NULL){
		printf("Fila Inexistente - Crie a fila primeiro");
		return;
	}

	TNodo *nodoaux;
	nodoaux = lista->first;

	if(lista->first == lista->last) {
		lista->first = NULL;
		lista->last = NULL;
	}
	else {
		//Primeiro elemento da fila é substituido pelo antigo segundo elemento da fila
		lista->first = lista->first->proximo; 
	}
	free(nodoaux);
	printf("\nRemovido com Sucesso !!\n");

}

void imprimeLista(Tdescritor* lista) {
	if(lista == NULL) {
		printf("Fila Inexistente - Crie a fila primeiro");
		return;
	}
		TNodo *aux = lista->first;
	if(lista->first == NULL) {
		printf("\n ########### WARNING ############## \n Lista Vazia\n");
	}
	else {
		while(aux) {
			printf("Nome: %s \nNumero: %d \n\n", aux->dados->nome, aux->dados->numero);
			aux = aux->proximo;	
		}
	}
}

int main(int argc, char *argv[]) {
	
	Tdescritor* lista = NULL;
	int opcao,numero;
	char nome[20];
	while(opcao != 5){
		
		printf("\n----------------------------------------");
		printf("\n     Estrutura de Dados I - Fila");
		printf("\n----------------------------------------");
		printf("\n1 - Criar Fila");
		printf("\n2 - Inserir");
		printf("\n3 - Remover");
		printf("\n4 - Imprimir Fila");
		printf("\n5 - Fechar Programa");
		printf("\n\nEscolha sua opcao:");
		scanf("%d", &opcao);
		if(opcao == 1) {
			lista = criaLista();
			printf("Fila criada com Sucesso !");
		}
		if(opcao == 2) {
			if(lista) {
				printf("\n------------------------------");
				printf("\n     Inserir Valores");
				printf("\n------------------------------");
				printf("\nDigite o numero da matricula:");
				scanf("%d", &numero);
				printf("\nDigite o nome do aluno:");
				scanf("%s", nome);
				Tdados* dados = insereDados(numero, nome);
				insereFim(lista, dados);
			}
			else {
				printf("Fila Inexistente - Crie a fila primeiro");
		
			}
			
		}
		if(opcao == 3) {
			removeInicio(lista);
		}
		if(opcao == 4) {
			printf("\n-------- FILA --------\n");
			imprimeLista(lista);
		}
	}
}
