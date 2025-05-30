#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct funcionario {
    int ID;
    char nome[30];
    int idade;
    float salario;
} FUNCIONARIO;

void dados(FUNCIONARIO *f) {
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

void drel_salario_corrigido(float *ptr_salario) {
    *ptr_salario = *ptr_salario * 1.10;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    FUNCIONARIO funcionarios[5];

    for (int i = 0; i < 5; i++) {
        printf("\nFuncionario %d\n", i + 1);
        dados(&funcionarios[i]);
    }

    printf("\n\n\n\t----- Dados Dos Funcionarios -----\n");
    for (int i = 0; i < 5; i++) {
        printf("\n- Dados do Funcionario %d\n", i + 1);
        printf("ID: %d\n", funcionarios[i].ID);
        printf("Nome: %s\n", funcionarios[i].nome);
        printf("Idade: %d\n", funcionarios[i].idade);
        printf("Salario: %.2f\n", funcionarios[i].salario);
    }

    printf("\n\n\t----- Salario Reajustado -----\n");
    for (int i = 0; i < 5; i++) {
        drel_salario_corrigido(&funcionarios[i].salario);
        printf("\nFuncionario %d\n", i + 1);
        printf("Nome: %s\n", funcionarios[i].nome);
        printf("Seu salario reajustado �: %.2f\n", funcionarios[i].salario);
    }

    return 0;
}
