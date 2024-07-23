#include<stdio.h>
#include<string.h>

int main()
{
    int x, y, a, b, sum=0, i;
    int arr[5][5]={
                        {1,2,3,4,3},
                        {2,3,1,4,5},
                        {6,3,1,1,4},
                        {3,4,5,1,3},
                        {2,4,5,6,7},
                    };
   
    printf("Enter coordinates : \n");
    scanf("%d%d",&x,&y);
   
    for(i=0;i<5;i++)
    {
        sum+=arr[x][i] + arr[i][y];
    }
    a = x+1;
    b = y+1;
    while((b<5) && (a<5)) 
    {
        sum+=arr[a++][b++];
    }
    a = x-1;
    b = y-1;
    while((a>=0) && (b>=0))
    {
        sum+=arr[a--][b--];
    }
    a = x-1;
    b = y+1;
    while((a>=0) && (b<5))   
    {
        sum+=arr[a--][b++];
    }
    a = x+1;
    b = y-1;
    while((a<5) && (b>=0))
    {
        sum+=arr[a++][b--];
    }
   
    printf("Required sum = %d\n",sum);
    return 0;
}

