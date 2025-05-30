#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "pt-BR");

    FILE *f1, *f2;
    f1 = fopen("arq1.txt", "w");
    f2 = fopen("arq2.txt", "w");

    if (f1 == NULL || f2 == NULL) {
        printf("Erro na abertura dos arquivos!\n");
        system("pause");
        exit(1);
    }

    char texto1[100];
    printf("Digite um texto: \n");
    fgets(texto1, sizeof(texto1), stdin);

    for (int i = 0; i < strlen(texto1); i++) {
        fputc(texto1[i], f1);
    }
    fclose(f1);

    f1 = fopen("arq1.txt", "r");
    if (f1 == NULL) {
        printf("Erro ao reabrir arq1.txt para leitura!\n");
        system("pause");
        exit(1);
    }

    f2 = fopen("arq2.txt", "w");
    if (f2 == NULL) {
        printf("Erro ao abrir arq2.txt para escrita!\n");
        system("pause");
        exit(1);
    }

    char ch;
    while ((ch = fgetc(f1)) != EOF) {
        fputc(toupper(ch), f2);
    }

    fclose(f1);
    fclose(f2);

    printf("\n\nTexto original e texto em mai�sculo foram gravados nos arquivos.\n\n");

    system("pause");
    return 0;
}
