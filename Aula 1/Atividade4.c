#include <stdio.h>
#include <stdlib.h>

int main() {
    int v1[5], v2[5];
    int i, j;
    int encontrou = 0;

    for (i = 0; i < 5; i++) {
        printf("\nInforme o valor do elemento %d do vetor 1: ", i + 1);
        scanf("%d", &v1[i]);
    }

    for (j = 0; j < 5; j++) {
        printf("\nInforme o valor do elemento %d do vetor 2: ", j + 1);
        scanf("%d", &v2[j]);
    }

    printf("\nVetor 1: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", v1[i]);
    }

    printf("\nVetor 2: ");
    for (j = 0; j < 5; j++) {
        printf("%d ", v2[j]);
    }

    printf("\n\nCompara��o de valores:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (v1[i] == v2[j]) {
                printf("Valores iguais: %d na posi��o %d do v1 e %d do v2\n", v1[i], i + 1, j + 1);
                encontrou = 1;
            }
        }
    }

    if (!encontrou) {
        printf("\nN�o h� valores iguais entre os vetores.\n");
    }

    printf("\n");
    system("pause");
    return 0;
}
