#include <stdio.h>
#include <stdlib.h>

int func(int n);
int interativa(int n);

int main(){
    int n, resultado, esc;
    printf("Escolha a forma de calcular(R(recursiva)/I(interativa)):\n");
    scanf("%c", &esc);

    switch(esc){
        case 'R':
        case'r':
            printf("\tVersao recursiva\n");
            printf("Entre com um valor: ");
            scanf("%d", &n);
            resultado = func(n);
            printf("Resultado: %d\n\n", resultado);
            break;
        case 'I':
        case'i':
            printf("\n\n\tVersao interativa\n");
            printf("Entre com um valor: ");
            scanf("%d", &n);
            resultado = interativa(n);
            printf("Resultado: %d\n\n", resultado);
            break;
        default:
            printf("Opcao invalida!");
            break;
    }
    return 0;
}

int func(int n){
    if(n == 0){
        return 0;
    }
    return (n + func(n-1));
}

int interativa(int n){
    int total = 0;
    for(; n > 0; n--){
        total = total + n;
    }
    return(total);
}
