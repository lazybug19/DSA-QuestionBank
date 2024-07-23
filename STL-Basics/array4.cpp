//left rotation

#include <stdio.h>
int main()
{   int s, r;
    printf("Enter array size: ");
    scanf("%d", &s);
    printf("Enter no. of times of rotation: ");
    scanf("%d", &r);
    int x[s];
    printf("Enter array elements: ");
        for (int j=0; j<s; j++)
        {
            scanf("%d", &x[j]);
        }
    printf("Required array: ");
        for(int q=0; q<r; q++)
        {
            for(int i=0; i<s-1; i++)
            {
                int n=0;
                n=x[i];
                x[i]=x[i+1];
                x[i+1]=n;
            }
        }
    for(int k=0; k<s; k++)
    {
        printf("%d", x[k]);
        for(int l=0; l<s-1; l++)
        {
            printf(" ");
            break;
        }
    }
    return 0;
}
//right rotation

#include <stdio.h>
int main()
{   int s, r;
    printf("Enter array size: ");
    scanf("%d", &s);
    printf("Enter no. of times of rotation: ");
    scanf("%d", &r);
    int x[s];
    printf("Enter array elements: ");
        for (int j=0; j<s; j++)
        {
            scanf("%d", &x[j]);
        }
    printf("Required array: ");
        for(int q=0; q<r; q++)
        {
            for(int i=s-1; i>=1; i--)
            {
                int n=0;
                n=x[i];
                x[i]=x[i-1];
                x[i-1]=n;
            }
        }
    for(int k=0; k<s; k++)
    {
        printf("%d", x[k]);
        for(int l=0; l<s-1; l++)
        {
            printf(" ");
            break;
        }
    }
    return 0;
}

//removing a particular element from string

#include <iostream>
using namespace std;

int main()
{   string s = "youtube";
    int x = sizeof(s);
    int k=0;
    for (int i=0; i<7; i++)
        {   
            s[i]=s[i+k];
            if (s[i] == 'u')
            {
               i--;
               k++;
            }
        }       
    cout << s;
    return 0;
}