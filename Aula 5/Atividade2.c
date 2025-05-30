#include <stdio.h>
#include <stdlib.h>


int main() {
    int a,b,*c,*d;

    printf("Valor de A: ");
    scanf("%d", &a);
    printf("Valor de B: ");
    scanf("%d", &b);

    c=&a;
    d=&b;

    printf("\n\n");

    if(c > d){
        printf("(A) � o maior valor, e esta no endere�o %p\n", c);
        printf("Valor de A: %d\n\n", a);
    } else{
        printf("(B) � o maior valor, e esta no endere�o %p\n", d);
        printf("Valor de B: %d\n\n", b);
    }

    return 0;
}
