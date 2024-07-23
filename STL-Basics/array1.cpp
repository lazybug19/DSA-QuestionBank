// array call
#include <stdio.h>

int *array (int *n)
{
    printf("Enter the elements of array: ");
    for (int i = 0; i <7; i++)
    {
        scanf("%d", &n[i]);
    }
    return n;
} 

int main()

{
    int *p;
    int n[7];
    p= array(n);
    printf("Elements of array are:\n");
    for (int i = 0; i < 7; i++)
    {
        printf("%d", p[i]);
        for (int i = 0; i < 6; i++)
        {
            printf(" ");
            break;
        }
    }
    return 0;

}
//swapping every odd/even indexed element with prev/after element of array
#include <iostream>
using namespace std;

int main()
{   int y;
    cin >> y;
    int x[y];
    for (int j=0; j<y; j++)
    {
        cin >> x[j];
    }
    for(int i=0; i<y; i++)
    {
        int n;
        if(i%2==0)
        {
            n=x[i];
            x[i]=x[i+1];
            x[i+1]=n;
        }
    }
    for(int k=0; k<y; k++)
    {
        cout << x[k] << " ";
    }
    return 0;
}

