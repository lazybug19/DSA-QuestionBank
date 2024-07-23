//shifting by p elements

#include <iostream>
using namespace std;

int main()
{   int y, p;
    cout << "Enter array size: ";
    cin >> y;
    cout << "Enter no. of elements to shift: ";
    cin >> p;
    int x[y];
    cout << "Enter array elements: ";
        for (int j=0; j<y; j++)
        {
            cin >> x[j];
        }
    cout << "New array: ";
        for(int q=1; q<=p; q++)
        {
            for(int i=0; i<=y-p; i++)
            {
                int n=0;
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

C:
#include <stdio.h>

int main()
{   int s, r, t=s-r+1;
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
        //for(int q=0; q<r; q++)
        //{
            for(int i=0; i<=t; i++)
            {
                int n=0;
                n=x[i];
                x[i]=x[i+1];
                x[i+1]=n;
            }
            //t--;
       // }
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