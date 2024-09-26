#include <stdio.h>

int main() {
    int number;
    unsigned long long factorial = 1;
    printf("Insira um número inteiro: ");
    scanf("%d", &number);
    if (number < 0) {
        printf("Fatoriais não são definidos para números negativos.\n");
        return 1;
    }
    for(int i = 1; i <= number; ++i){
        factorial *= i;
    }
    printf("Fatorial de %d = %llu\n", number, factorial);
    return 0;
}
