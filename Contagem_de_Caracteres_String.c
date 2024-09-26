#include <stdio.h>
#include <string.h>

int main(){
    char str[1000];
    printf("Insira uma String: ");
    fgets(str, sizeof(str), stdin);
    int length = strlen(str);
    if(str[length - 1] == '\n') length--;
    printf("Número de caracteres: %d\n", length);
    return 0;
}
