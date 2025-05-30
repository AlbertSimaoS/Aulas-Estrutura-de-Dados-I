#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str[80], cons;
    int quant = 0;

    printf("Digite uma palavra: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    for(int i = 0; i < strlen(str); i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            quant++;
        }
    }
    printf("A palavra possui: %d vogais\n\n", quant);

    printf("Digite uma cosoante: ");
    scanf("%c", &cons);

    for(int i = 0; i < strlen(str); i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            str[i] = cons;
        }
    }
    printf("%s", str);



    return 0;
}
