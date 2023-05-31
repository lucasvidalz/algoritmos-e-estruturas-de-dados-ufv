/*----------------------------------------------------------------------------------------------
|               Código feito por Lucas Moura Vidal da Silva em 30/03/2023                      |      
|---------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxcodigo 7
#define maxnome 50

//definindo estrutura
typedef struct Disciplina {

    char codigo[maxcodigo];
    char nome[maxnome];
    int pva;
    struct Disciplina* prox;
} Disciplina;

//atribuimos as variaveis lidas as das estrutura como tambem alocamos memoria

Disciplina* criar_disciplina(char codigo[], char nome[], int pva) {

    //alocando espaço na memoria
    Disciplina* disciplina = (Disciplina*) malloc(sizeof(Disciplina));

    //atribuindo as variaveis lidas do usuario as variaveis da estrutura
    strcpy(disciplina->codigo, codigo);
    strcpy(disciplina->nome, nome);
    disciplina->pva = pva;
    disciplina->prox = NULL;
    return disciplina;
}

// funcao que inseri disciplinas na lista

void inserir_disciplina(Disciplina** lista, char codigo[], char nome[], int pva) {

    Disciplina* disciplina = criar_disciplina(codigo, nome, pva);
    disciplina->prox = *lista;
    *lista = disciplina;
}

// funcao que remove disciplinas na lista

void remover_disciplina(Disciplina** lista, char codigo[]) {

    Disciplina* atual = *lista;
    Disciplina* anterior = NULL;

    while (atual != NULL) {

        if (strcmp(atual->codigo, codigo) == 0) {
            if (anterior == NULL) {
                *lista = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual);
            printf("Disciplina com codigo %s removida.\n", codigo);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }

    printf("Disciplina com codigo %s nao encontrada.\n", codigo);

}

// funcao para imprimir as disciplinas ministradas na sala 227

void exibir_disciplinas_lab(Disciplina* lista) {

    Disciplina* atual = lista;
    int i = 0;

    while (atual != NULL) {

        if (atual->pva == 227) {
            printf("%s - %s\n", atual->codigo, atual->nome);
            i++;
        }
        atual = atual->prox;
    }

    if (i == 0) {
        printf("Nenhuma disciplina sera ministrada no laboratorio de informatica.\n");
    }
}
//funcao para exibir o menu de opcoes
void exibir_menu() {

    printf("1. Inserir uma nova disciplina no inicio da lista.\n");
    printf("2. Remover disciplina pelo codigo.\n");
    printf("3. Exibir somente as disciplinas que serao ministradas no laboratorio de informatica.\n");
    printf("4. Sair do programa.\n");
}

int main() {

    Disciplina* lista = NULL; //inicializando a lista

    while (1) {

        int escolha, pva;
        char codigo[maxcodigo];
        char nome[maxnome];

        exibir_menu();
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o codigo da disciplina: ");
                fflush(stdin);
                gets(codigo);

                printf("Digite o nome da disciplina: ");
                fflush(stdin);
                gets(nome);

                printf("Digite o PVA da disciplina: ");
                scanf("%d", &pva);

                inserir_disciplina(&lista, codigo, nome, pva);
                printf("Disciplina com codigo %s inserida.\n", codigo);
                break;

            case 2:
                printf("Digite o codigo da disciplina para remover: ");
                fflush (stdin);
                gets(codigo);
                remover_disciplina(&lista, codigo);
                break;

            case 3:
            printf("Disciplinas que serao ministradas no laboratorio de informatica:\n");
            exibir_disciplinas_lab(lista);
            break;

            case 4:
                exit(4);

        default:
            printf("Escolha invalida. Digite um numero de 1 a 4.\n");
            break;
    }

    printf("\n\n");
    }

    return 0;
    }


