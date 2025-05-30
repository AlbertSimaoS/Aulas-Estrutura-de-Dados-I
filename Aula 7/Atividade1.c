#include <stdio.h>
#include <stdlib.h>

int main(){
    int *vet = NULL, i, n = 12;

    vet = (int*) malloc(n * sizeof(int));
    for( i = 0; i < n; i++){
        vet[i] = i;
        if(i % 2 != 0){
            printf("%d - ", vet[i]);
        }
    }
    return 0;
}
