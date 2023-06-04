/*Programa que permite o usuário Inserir, Remover e Exibir livros em uma pilha dinâmica
atráves do seu título como também informar o número de páginas de cada um deles*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Livro {

    char titulo[50];
    int numPaginas;
    struct Livro* prox;

} Livro;

typedef struct Pilha {
    Livro* topo;
} Pilha;

void pilha_inicializar(Pilha* pilha) {
    pilha->topo = NULL;
}

int pilha_vazia(Pilha* pilha) {
    return (pilha->topo == NULL);
}


void empilhar(Pilha* pilha, char* titulo, int numPaginas) {

    Livro* novoLivro = (Livro*)malloc(sizeof(Livro));

    strcpy(novoLivro->titulo, titulo);
    novoLivro->numPaginas = numPaginas;
    novoLivro->prox = pilha->topo;
    pilha->topo = novoLivro;

}

Livro* desempilhar(Pilha* pilha) {

    if (pilha_vazia(pilha)) {
        return NULL;
    }

    Livro* livroRemovido = pilha->topo;
    pilha->topo = pilha->topo->prox;

    return livroRemovido;
}

void pilha_exibirNClassica(Pilha* pilha) {

    Livro* atual = pilha->topo;

    while (atual != NULL) {
        printf("Titulo: %s, Numero de Paginas: %d\n", atual->titulo, atual->numPaginas);
        atual = atual->prox;
    }
}

int main() {

    Pilha pilha;
    pilha_inicializar(&pilha);

    int numPaginas, opcao = 0;
    char titulo[50];

    while (opcao != 4) {

        printf("Escolha uma opcao:\n");
        printf("1. Inserir um novo livro no topo da pilha\n");
        printf("2. Remover um livro do topo da pilha\n");
        printf("3. Exibir os elementos da pilha usando a impressao nao classica\n");
        printf("4. Sair\n");

        printf("Digite a opcao escolhida: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:

                printf("Digite o titulo do livro: ");
                fflush(stdin);
                gets(titulo);

                printf("Digite o numero de paginas do livro: ");
                scanf("%d", &numPaginas);

                empilhar(&pilha, titulo, numPaginas);
                printf("Livro inserido na pilha.\n");
                break;

            case 2:

                if (pilha_vazia(&pilha)) {
                    printf("A pilha esta vazia.\n");

                } else {

                    Livro* livroRemovido = desempilhar(&pilha);
                    printf("Livro removido: Titulo: %s, Numero de Paginas: %d\n", livroRemovido->titulo, livroRemovido->numPaginas);
                    free(livroRemovido);
                }
                break;

            case 3:

                if (pilha_vazia(&pilha)) {
                    printf("A pilha esta vazia.\n");
                } else {
                    printf("Elementos da pilha:\n");
                    pilha_exibirNClassica(&pilha);

                }
                break;

            case 4:

                printf("Encerrando o programa.\n");
                // Libera a memória dos livros restantes na pilha
                while (!pilha_vazia(&pilha)) {

                    Livro* livroRemovido = desempilhar(&pilha);
                    free(livroRemovido);
                }
                break;

            default:
                printf("Opcao invalida.\n");
                }

                printf("\n");
            }

    return 0;

}
