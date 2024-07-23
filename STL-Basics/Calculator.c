#include <stdio.h>
#include <math.h>

int main(){
    float n1, n2;
    int n3, n4;
    char oper;
    
    printf("Enter the operator: ");
    scanf("%c", &oper);
    if (oper == '+') {
        printf("Enter the operands: ");
        scanf("%f%f", &n1, &n2);
        printf("Result = %f", n1 + n2);}
        else if (oper == '-') {
        printf("Enter the operands: ");
        scanf("%f%f", &n1, &n2);
        printf("Result = %f", n1 - n2);}
        else if (oper == '*') {
        printf("Enter the operands: ");
        scanf("%f%f", &n1, &n2);
        printf("Result = %f", n1 * n2);}
        else if (oper == '/'){
        printf("Enter the operands: ");
        scanf("%f%f", &n1, &n2);
        {
            if (n2 != 0)
            printf("Result = %f", n1 / n2);
            else printf("Error!");
        } }
        else if (oper == '%') {
        printf("Enter the operands: ");
        scanf("%d%d", &n3, &n4);
        printf("Result = %d", n3 % n4);}
    else printf("Operator is incorrect!");
    return 0;
} 