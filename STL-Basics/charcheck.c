#include<stdio.h> 

int main() {
char ch;
printf("Enter a character:");
scanf("%c", &ch); 

if (ch< 32) 
    printf("control\n");
else if (ch >= 32) 
{
    printf("printable\n");
    if (ch == 32) printf("space\n");
    if (ch > 32) 
    {
        printf("graphical\n");
        if ((ch>= 65 && ch <=90) || (ch>= 97 && ch <= 122) || (ch>= 48 && ch <=57)) 
        {
            printf("alphanumeric\n"); 
            if (ch >= 48 && ch <= 57) 
                printf( "digit\n"); 
            else 
            {
                printf("alphabetic\n"); 
                if (ch >= 65 && ch <= 90) 
                    printf("upper case\n");
                else 
                    printf("lower case\n");
            }
        }
        if((ch >= 33 && ch <= 47) || (ch >= 58 && ch <= 64) || (ch>= 91 && ch <= 96) || (ch>= 123 && ch <= 126)) 
            printf("punctuation\n");
    }
}
else 
    printf("Unknown character printed"); 
return 0; 
}