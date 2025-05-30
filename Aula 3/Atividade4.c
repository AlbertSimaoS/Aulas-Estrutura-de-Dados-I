#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str1[20];
    char str2[20];

    printf("Digite uma palavra: ");
    scanf("%s", str1);

    printf("Digite outra palavra: ");
    scanf("%s", str2);

    if (strstr(str1, str2)) {
        printf("\nA palavra \"%s\" est� na palavra \"%s\".\n", str2, str1);
    } else {
        printf("\nA palavra \"%s\" n�o est� na palavra \"%s\".\n", str2, str1);
    }

    printf("\n\n\n");
}
