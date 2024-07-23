#include<string.h> 
#include <stdio.h>

int main(){

    int row=0,col=0,i=0;
    char name[50];
    printf("Enter your name:\n"); 
    scanf("%s",name); 
    int len = strlen(name); 
    while(row<20+len){
        col=0;
        if((row>=10) && (row<10+len))
            {while(col<4)
                { printf("*"); 
                  col++;
                }
            printf("%c", name[i]);
            col++;
            while(col<9)
                { printf("*"); 
                  col++;
                } 
            i++;
            }
        else 
        {while(col<9)
            { printf("*");
              col++;
            }
        }
        printf("\n");
        row++;
    }

    return 0;
}