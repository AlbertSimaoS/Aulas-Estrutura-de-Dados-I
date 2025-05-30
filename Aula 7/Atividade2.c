#include <stdio.h>
#include <stdlib.h>

int main(){
    int *vet = NULL, i, n, nota = 0;

    printf("Quantos alunos: ");
    scanf("%d", &n);
    vet = (int*) malloc(n * sizeof(int));
    for( i = 0; i < n; i++){
        printf("Digite a nota do %d aluno: ", i+1);
        scanf("%d", &vet[i]);
    }

    for(i = 0; i < n; i++){
        printf("Nota do %d Aluno: %d\n", i+1, vet[i]);
        nota += vet[i];
        printf("%d\n", nota);
    }

    printf("\n\tMedia Aritmetica da turma:  %d", nota/n);
    return 0;
}
