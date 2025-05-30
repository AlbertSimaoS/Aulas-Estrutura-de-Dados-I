#include <stdio.h>
#include <stdlib.h>
 void soma(int *p){
    *p = *p + 100;
 }


int main() {
    int a, b, c;
    int *d, *e, *f;

    printf("Valor pra A: ");
    scanf("%d", &a);
    printf("Valor pra B: ");
    scanf("%d", &b);
    printf("Valor pra C: ");
    scanf("%d", &c);

    d = &a;
    e = &b;
    f = &c;

    printf("%d, %d, %d \n", a,b,c);

    soma(d);
    soma(e);
    soma(f);

    printf("%d, %d, %d", a,b,c);



    return 0;
}
