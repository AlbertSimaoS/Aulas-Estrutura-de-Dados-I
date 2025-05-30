#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Digite um n�mero: ");
    scanf("%d", &n);

    if (n > 4 || n < 1) {
        printf("0");
    } else {
        if (n == 1) {
            printf("A");
        } else if (n == 2) {
            printf("B");
        } else if (n == 3) {
            printf("C");
        } else if (n == 4) {
            printf("D");
        }
    }

    printf("\n\n\n");
    system("pause");
    return 0;
}
