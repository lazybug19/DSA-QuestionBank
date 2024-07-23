int main()
int n=9;
for(int row=n; row>=1; row--){
     for (int y=1; y<=row-1; y++)
        {
         printf("%d", y);
        }
         for(int z=1; z<=n; z++)
        {
            if ( row==1 || row==n || z==1 || z==n )
                printf("*");
            else
                printf("2012012");
        }
     print("\n");
 }
return 0;
{

