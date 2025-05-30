#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct funcionario {
    int ID;
    char nome[30];
    int idade;
    float salario;
};

void dados(struct funcionario *f) {
    printf("Digite seu ID: ");
    scanf("%d", &f->ID);
    getchar();

    printf("Digite seu Nome: ");
    fgets(f->nome, sizeof(f->nome), stdin);
    f->nome[strcspn(f->nome, "\n")] = '\0';

    printf("Digite sua Idade: ");
    scanf("%d", &f->idade);

    printf("Digite seu Salario: ");
    scanf("%f", &f->salario);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    struct funcionario funcionarios[5];

    for (int i = 0; i < 5; i++) {
        printf("\nFuncionario %d\n", i + 1);
        dados(&funcionarios[i]);
    }

    printf("\n\n\n\t-----Dados Dos Funcionarios-----\n");
    for (int i = 0; i < 5; i++) {
        printf("\n- Dados do Funcionario %d\n", i + 1);
        printf("ID: %d\n", funcionarios[i].ID);
        printf("Nome: %s\n", funcionarios[i].nome);
        printf("Idade: %d\n", funcionarios[i].idade);
        printf("Salario: %.2f\n", funcionarios[i].salario);
    }

    return 0;
}
