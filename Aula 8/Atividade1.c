#include <stdio.h>
#include <stdlib.h>

int interativa(int n);
int recursiva(int n);

int main(){
    int n, resultado;
    printf("Entre com um numero:");
    scanf("%d", &n);

    printf("\tVersao interativa\n");
    resultado = interativa(n);

    printf("\tVersao recursiva\n");
    resultado = recursiva(n);

    return 0;
}

int interativa(int n){
    for(n ; n >= 0; n--){
        printf("%d\n", n);
    }
}

int recursiva(int n){
    printf("%d\n", n);
    if(n == 0){
        return(n);
    }
    return recursiva(n-1);
}
