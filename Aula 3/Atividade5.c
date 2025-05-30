#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str[80];

    printf("Digite uma palavra: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';


    for(int i = 0; i < strlen(str); i++){
        if(str[i] != ' ' str[i] >= 'a' && str[i] <= 'z'){
            str[i] = str[i] - 32;
        }
    }

    printf("Palavra com letras em mai�sculo: %s\n", str);

    return 0;
}
