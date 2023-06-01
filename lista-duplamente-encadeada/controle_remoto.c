/*----------------------------------------------------------------------------------------------
|               Código feito por Lucas Moura Vidal da Silva em 30/03/2023                      |
|---------------------------------------------------------------------------------------------*/
/*Esse programa apresenta um menu de opções, de uma lista duplamente encadeada usada na implementação do controle remoto de
uma TV contendo o nome e o número do canal.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char nome[30];
    int numero;
    struct No *ant;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
} Lista;




void lista_inicializar(Lista *lista) {

    lista->inicio = NULL;
    lista->fim = NULL;
}


No* alocarNo(char nome[], int numero) {

    No *novo = (No*) malloc(sizeof(No));

    if (novo != NULL) {

        strcpy(novo->nome, nome);
        novo->numero = numero;
        novo->ant = NULL;
        novo->prox = NULL;
    }
    return novo;
}


void desalocarNo(No *no) {

    free(no);
}

int lista_vazia(Lista *lista) {

    return (lista->inicio == NULL);
}


void lista_inserirFim(Lista *lista, char nome[], int numero) {

    No *novo = alocarNo(nome, numero);

    if (novo != NULL) {

        if (lista_vazia(lista)) {
            lista->inicio = novo;
        } else {
            lista->fim->prox = novo;
            novo->ant = lista->fim;
        }

        lista->fim = novo;
    }
}


void lista_exibir(Lista *lista) {

    No *atual = lista->inicio;

    while (atual != NULL) {
        printf("Canal: %s | Numero: %d\n", atual->nome, atual->numero);
        atual = atual->prox;
    }
}

No* lista_pesquisar(Lista *lista, char nome[]) {

    No *atual = lista->inicio;

    while (atual != NULL) {

        if (strcmp(atual->nome, nome) == 0) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;

}
//---------------------------------------------------------------------------------------------------

void lista_remover(Lista *lista, No *no) {

    if (no == lista->inicio && no == lista->fim) {

        lista->inicio = NULL;
        lista->fim = NULL;

    } else if (no == lista->inicio) {
        lista->inicio = no->prox;
        lista->inicio->ant = NULL;

    } else if (no == lista->fim) {
        lista->fim = no->ant;
        lista->fim->prox = NULL;

    } else {

        no->ant->prox = no->prox;
        no->prox->ant = no->ant;
    }
    desalocarNo(no);
}

int main() {

    Lista lista;
    lista_inicializar(&lista);
    int opcao, numero;
    char nome[30];
    No *no;

    do {
        printf("1 - Inserir novo canal\n");
        printf("2 - Exibir canais\n");
        printf("3 - Remover canal\n");

        printf("Escolha uma opcao:");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:

                printf("Nome do canal: ");
                fflush(stdin);
                gets(nome);

                printf("Numero do canal: ");
                scanf("%d", &numero);

                lista_inserirFim(&lista, nome, numero);
                printf("Canal inserido com sucesso!\n");

                break;
            case 2:
                if (lista_vazia(&lista)) {
                    printf("Lista vazia!\n");

                }else{
                    printf("Lista de canais:\n");
                    lista_exibir(&lista);
            }

            break;
        	case 3:
            if (lista_vazia(&lista)) {

                printf("Lista vazia!\n");

            } else {

                printf("Nome do canal a ser removido: ");
                fflush(stdin);
                gets(nome);

                no = lista_pesquisar(&lista, nome);

                if (no == NULL) {

                    printf("Canal nao encontrado!\n");

                } else {
                    lista_remover(&lista, no);
                    printf("Canal removido com sucesso!\n");
                }
            }

            break;
            default:
            printf("Opcao invalida!\n");
            break;
        }
    } while (opcao != 0);

    return 0;
}
