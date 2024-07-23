#include <stdio.h>

int main()
{
    int n, carry = 1;
    
    printf("Enter number of bits:\n"); 
    scanf("%d",&n);
    
    char binary[n+1];
    char onescomplement[n+1];
    char twoscomplement[n+1];
    
    printf("Enter binary number:\n"); 
    scanf("%s", binary);
    
    for(int i=0; i<n; i++)
    {
        switch (binary[i] == '0')
        {
        
            case 1: onescomplement[i]='1';
            break;
            
            case 0: onescomplement[i]='0';
            break;
        }
    }
    
    onescomplement[n] = '\0'; 
    printf("1's complement of %s: %s\n",binary, onescomplement); 
    
    for(int i=n-1; i>=0; i--)
    {
        switch (onescomplement[i] == '1'^carry)
        {
            case 0: 
                twoscomplement[i] ='0';
            break;
            
            case 1: 
                twoscomplement[i] ='1';
                carry = 0;
            break;
        }
    }
    
    twoscomplement[n] = '\0'; 
    printf("2's complement of %s: %s\n",binary, twoscomplement);
    
    return 0;

}