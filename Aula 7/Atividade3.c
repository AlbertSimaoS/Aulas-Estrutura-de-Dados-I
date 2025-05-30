#include <stdio.h>
#include <stdlib.h>

int main(){
    int linhas = 2, colunas = 2, i, j;
    int **matriz;
    matriz = (int **) malloc(linhas * sizeof(int*));
    for(i=0; i < linhas; i++){
        matriz[i] = (int*) malloc(colunas * sizeof(int));
    }

    printf("\tElemento da 1 matriz: \n");
    for(i = 0; i < linhas; i++){
        for(j=0; j<colunas; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("\n\n\n");
    printf("\tMatriz 1\n");
    for(i = 0; i < linhas; i++){
        for(j=0; j<colunas; j++){
            printf("%2d   ", matriz[i][j]);
        }
        printf("\n\n");
    }


    int **matriz2;
    matriz2 = (int **) malloc(linhas * sizeof(int*));
    for(i=0; i < linhas; i++){
        matriz2[i] = (int*) malloc(colunas * sizeof(int));
    }

    printf("\tElemento da 2 matriz: \n");
    for(i = 0; i < linhas; i++){
        for(j=0; j<colunas; j++){
            scanf("%d", &matriz2[i][j]);
        }
    }
    printf("\n\n\n");
    printf("\tMatriz 2\n");
    for(i = 0; i < linhas; i++){
        for(j=0; j<colunas; j++){
            printf("%2d   ", matriz2[i][j]);
        }
        printf("\n\n");
    }



    printf("\tMatriz da soma:\n");
     for(i = 0; i < linhas; i++){
        for(j=0; j<colunas; j++){
            printf("%2d   ", matriz[i][j] + matriz2[i][j]);
        }
        printf("\n");
    }

    return 0;
}
