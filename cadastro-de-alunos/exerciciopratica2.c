/*----------------------------------------------------------------------------------------------
|               Código feito por Lucas Moura Vidal da Silva em 30/03/2023                      |      
|---------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

struct salunos {

    int matricula;
    char nome [45];
    float notafinal;

};
int main () {



    int n;
    printf("Cadastro de Alunos(MATRICULA, NOME E NOTAFINAL)\n");
    printf("Quantos alunos serao adicionados ? ");
    scanf("%d", &n);

    struct salunos aluno[n];

    for (int i=0; i<n;i++){
        printf("\nDigite os dados do aluno %d ", i+1);

        printf("\nmatricula do aluno %d: ", i+1);
        scanf("%d", &aluno[i].matricula);

        printf("\nNome do %d: ", i+1);
        fflush(stdin);
        gets(aluno[i].nome);

        printf("\nNota final %d: ", i+1);
        scanf("%f", &aluno[i].notafinal);

    }
    float aux_soma, soma=0;

    //percorrendo o vetor e atribuindo notas ao aux_soma a fim de calcular a media das notas
    aux_soma = aluno[0].notafinal;

    for(int i=1; i<n;i++){

    soma = aux_soma + aluno[i].notafinal;
    aux_soma = soma;

    }
    //calculando e imprimindo a média das notas
    float media;

    media = aux_soma/n;

    printf("\n A media eh de %.2f", media);



    return 0;
}

