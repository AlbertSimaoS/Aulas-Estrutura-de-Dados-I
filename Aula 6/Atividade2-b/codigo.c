#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario {
    int ID;
    char nome[30];
    int idade;
    float salario;
} Funcionario;

int main() {
    FILE *fp = fopen("arqat2.txt", "rb");
    if (fp == NULL) {
        printf("Erro na abertura\n");
        system("pause");
        exit(1);
    }

    Funcionario f;

    // Pular os dois primeiros funcion�rios e ler o terceiro
    fseek(fp, 2 * sizeof(Funcionario), SEEK_SET);
    fread(&f, sizeof(Funcionario), 1, fp);

    printf("ID: %d \nNome: %s \nIdade: %d \nSalario: %.2f \n", f.ID, f.nome, f.idade, f.salario);

    fclose(fp);
    system("pause");
    return 0;
}
