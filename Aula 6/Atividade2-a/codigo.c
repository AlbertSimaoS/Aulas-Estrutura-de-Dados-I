#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario {
    int ID;
    char nome[30];
    int idade;
    float salario;
} Funcionario;

int main() {
    FILE *f = fopen("arqat2.txt", "wb");
    if (f == NULL) {
        printf("Erro na abertura\n");
        system("pause");
        exit(1);
    }

    int i, n = 5;
    Funcionario func[n];

    for (i = 0; i < n; i++) {
        printf("Informe o ID do funcionario: ");
        scanf("%d", &func[i].ID);
        getchar();

        printf("Informe o nome do funcionario: ");
        fgets(func[i].nome, sizeof(func[i].nome), stdin);
        func[i].nome[strcspn(func[i].nome, "\n")] = '\0';

        printf("Informe a idade do funcionario: ");
        scanf("%d", &func[i].idade);

        printf("Informe o salario do funcionario: ");
        scanf("%f", &func[i].salario);

        system("cls");
    }

    fwrite(func, sizeof(Funcionario), n, f);
    fclose(f);

    printf("Dados dos funcionarios gravados com sucesso!\n");
    system("pause");
    return 0;
}
