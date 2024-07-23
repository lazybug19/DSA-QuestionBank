#include <stdio.h>
#include <string.h>
 
int main()
{
    int count = 0, f, l, n, max, freq[100] = {0}, flag = 0;
    char str[100], check[100], c;
 
    printf("Enter the string: ");
    gets(str);
    printf("Enter character whose first & last occurence is to be found: ");
    c = getchar();
    for (int i = 0; i < strlen(str); i++)
    {
        if (c == str[i])
        {
            count++;
            if (count  == 1)
            {
                f = i;
                l = i;
                printf("First occurence: %d", f + 1);
            }
            else 
            {
                l = i;
            }
        }
    }
    printf("\nLast occurence: %d", l + 1);
    
    int j = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (i == 0)
        {
            check[j++] = str[i];
            freq[j - 1]++;
        }
        else
        {
            for (int k = 0; k  < j; k++)
            {
                if (str[i] == check[k])
                {
                    freq[k]++;
                    flag = 1;
                }
            }
            if (flag == 0)
            {
                check[j++] = str[i];
                freq[j - 1]++;
            }
            flag = 0;
        }
    }    
 
    for (int i = 0; i < j; i++)
    {
        if ((i == 0) && (check[i] != ' '))
        {
            max = freq[i];
            continue;
        }
        if ((max < freq[i]) && (check[i] != ' '))
        {
            max = freq[i];
            n = i;
        }
    }
 
    printf("\nHighest occurring character in the string = %c", check[n]);
    return 0;
}