#include <stdio.h>
#include <math.h>

int main(){
    int number, isPrime = 1;
    printf("Enter an integer: ");
    scanf("%d", &number);
    if(number <= 1){
        isPrime = 0;
    }
    else{
        for(int i = 2; i <= sqrt(number); i++){
            if(number % i == 0){
                isPrime = 0;
                break;
            }
        }
    }
    if(isPrime){
        printf("%d é um número primo.\n", number);
    }
    else{
        printf("%d não é um número primo.\n", number);
    }
    return 0;
}
