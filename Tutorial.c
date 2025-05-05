#include <stdio.h>
#include <stdlib.h>

int main()
{
    char operator;
    double num1;
    double num2;
    double result;

   
    printf("enter an operator ( + - * /): ");
    scanf("%c", &operator);

    printf("enter the first number: ");
    scanf("%lf", &num1);

    printf("enter the second number: ");
    scanf("%lf", &num2);

    switch(operator){
        case '+':
            result = num1 + num2;
            printf("\nresult: %lf", result);
            break;
        case '-':
            result = num1 - num2;
            printf("\nresult: %lf", result);
            break;
        case '*':
            result = num1 * num2;
            printf("\nresult: %lf", result);
            break;
        case '/':
            result = num1 / num2;
            printf("\nresult: %lf", result);
            break;

        default:
        printf("%c is not valide", operator);
    }

    return 0;
}