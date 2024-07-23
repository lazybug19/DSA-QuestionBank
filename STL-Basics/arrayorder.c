#include <stdio.h>

int main()
{
    int n;
    char m;

    printf("Enter index of array:\n");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    int s[n];
    for (int k=0; k<n; k++)
    {
        scanf("%d", &s[k]);
    }

    printf("Enter order of arrangement:\n");
    getchar();
    scanf("%c", &m);
    
    if (m == 'a')
    {
        for (int i=0; i<n-1; i++)//manually check n-1 iterations are sufficient
        {
            for (int j=0; j<n-1-i; j++)//manually check for each value of i how much loops are needed to satisfy the condition. Last digit onwards order comes in sequence.
            {
                int p=0;
                if(s[j]>s[j+1])
                {
                    p=s[j];
                    s[j]=s[j+1];
                    s[j+1]=p;
                }
            }
        }
        printf("Ascending order:\n");
    }
    
    else if (m == 'd')
    {
        for (int i=0; i<n-1; i++)//manually check n-1 iterations are sufficient
        {
            for (int j=0; j<n-1-i; j++)//manually check for each value of i how much loops are needed to satisfy the condition. Last digit onwards order comes in sequence.
            {
                int p=0;
                if(s[j]<s[j+1])
                {
                    p=s[j];
                    s[j]=s[j+1];
                    s[j+1]=p;
                }
            }
        }
        printf("Descending order:\n");
    }
    for (int q=0; q<n; q++)
    {
        printf("%d\n", s[q]);
    }
    return 0;
}
