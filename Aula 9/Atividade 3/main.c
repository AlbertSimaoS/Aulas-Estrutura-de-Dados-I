#include <stdio.h>
#include <stdlib.h>
#include "my_lab.h"

int main()
{
    char escolha;
    printf("\tCalculadora:\n\n");
    printf("Deseja fazer um calculo(S|N):");
    scanf("%c", &escolha);
    menu(escolha);
}
