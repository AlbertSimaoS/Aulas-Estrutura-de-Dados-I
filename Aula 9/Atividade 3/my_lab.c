#include <stdio.h>
#include <stdlib.h>
#include "my_lab.h"

struct conta {
    float x;
    float y;
    float z;
};

Conta *criaValores(float x, float y, float z) {
    Conta *c = (Conta *) malloc(sizeof(Conta));
    if (c != NULL) {
        c->x = x;
        c->y = y;
        c->z = z;
    }
    return c;
}

void liberaValores(Conta *c) {
    free(c);
}

void soma(Conta *c) {
    c->z = c->x + c->y;
}

void subtrai(Conta *c) {
    c->z = c->x - c->y;
}

void multiplica(Conta *c) {
    c->z = c->x * c->y;
}

void divide(Conta *c) {
    if (c->y != 0)
        c->z = c->x / c->y;
}

void menu(char escolha) {
    float n1 = 0, n2 = 0;
    char operacoes;
    Conta *c = criaValores(0, 0, 0);

    printf("Digite um valor: ");
    scanf("%f", &n1);
    getchar();
    c->x = n1;

    do {
        printf("Escolha a opera��o (+, -, *, /): ");
        scanf("%c", &operacoes);
        getchar();

        printf("Digite um valor: ");
        scanf("%f", &n2);
        getchar();
        c->y = n2;

        switch (operacoes) {
            case '+':
                soma(c);
                printf("Resultado: %.2f\n", c->z);
                c->x = c->z;
                break;
            case '-':
                subtrai(c);
                printf("Resultado: %.2f\n", c->z);
                c->x = c->z;
                break;
            case '*':
                multiplica(c);
                printf("Resultado: %.2f\n", c->z);
                c->x = c->z;
                break;
            case '/':
                if (c->y != 0) {
                    divide(c);
                    printf("Resultado: %.2f\n", c->z);
                    c->x = c->z;
                } else {
                    printf("Erro: divis�o por zero!\n");
                }
                break;
            default:
                printf("Escolha inv�lida!\n");
        }

        printf("Deseja fazer um novo c�lculo (S/N): ");
        scanf("%c", &escolha);
        getchar();
    } while (escolha == 's' || escolha == 'S');

    liberaValores(c);
}

