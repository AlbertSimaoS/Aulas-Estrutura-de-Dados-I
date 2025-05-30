#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *strupr(char *str){
    while(*str){
        *str = toupper(*str);
        str++;
    }
    return str;
}

char *strlwr(char *str){
    while(*str){
        *str = tolower(*str);
        str++;
    }
    return str;
}

int main(){
    char str[80];

    printf("Digite uma palavra: ");
    gets(str);

    strupr(str);
    printf("String Maiuscula: %s\n\n", str);

    strlwr(str);
    printf("String Minuscula: %s", str);


    printf("\n\n\n");
}
