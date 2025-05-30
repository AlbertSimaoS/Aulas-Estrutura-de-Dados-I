#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    char nome[100];
    int idade;
    float salario;

    printf("Digite seu nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("Digite sua Idade: ");
    scanf("%d", &idade);

    printf("Digite seu Sal�rio: ");
    scanf("%f", &salario);

    printf("    Nome: %s.\n    Idade: %d.\n    Sal�rio: %.2f.\n", nome, idade, salario);

    printf("\n\n\n");
}

