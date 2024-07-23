#include <stdio.h>
int main()
{
    int n=9;
    for(int row=n; row>=1; row--)
    {
        for (int y=1; y<=row-1; y++)
            {
             printf("%d", y);
            }
            if ( row==1 || row==n )
                for(int z=1; z<=n; z++)
                    printf("*");
            else  
                printf("*2012012*");
           
         printf("\n");
    }
    return 0;
}