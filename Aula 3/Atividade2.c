#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    char nome[10], sobre1[10], sobre2[10], espaco[10] = " ";

    printf("Digite seu nome: ");
    gets(nome);
    printf("Digite seu 1� Sobrenome: ");
    gets(sobre1);
    printf("Digite seu 2� Sobrenome: ");
    gets(sobre2);

    strcat(nome, espaco);
    strcat(nome, sobre1);
    strcat(nome, espaco);
    strcat(nome, sobre2);
    printf("\n\nNome completo: %s\n", nome);

    printf("\n\n\n");
}
