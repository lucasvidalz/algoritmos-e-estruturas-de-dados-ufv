#include <stdio.h>
#include <stdlib.h>
#define TAML 20
//definindo lista estatica
    typedef struct sLista{

    float num[TAML];
    int n;

    }LISTA;

//inicializando a lista

    void inicializar_lista(LISTA *ptrl){
    ptrl->n = (-1);
     }

//funcao para inserir verificar se lista esta vazia

     int lista_vazia(LISTA *ptrl){
     if(ptrl->n==(-1)){
        return 1;

     }else {
     return 0;
     }
     }
//funcao para inserir verificar se lista esta cheia

     int lista_cheia (LISTA *ptrl){
     if(ptrl->n+1==TAML){
        return 1;
     }else{
     return 0;
     }
     }
//funcao para inserir elemento no fim da lista
    int lista_inseri_fim(LISTA *ptrl, float elem){
    if(lista_cheia(ptrl)){
        printf("Erro - a lista está cheia");
        return 1;
    }
    ptrl->n++;
    ptrl->num [ptrl->n]=elem;
    return 0;

    }

int main(){


    LISTA *l;

    l = (LISTA*)malloc(sizeof(LISTA));


    return 0;
}
