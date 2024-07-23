#include <stdio.h>

int main()
{   
    char a[500];
    int l=0, w=0, s=0, c=0;
    int i=0;
    printf("Enter string:\n");
    scanf("%[^~]", a);
    while(a[i]!='\0')
    {
        switch(a[i]=='\n')
        {    
            case 1:
                l++;
                w++;
            break;
            
            case 0:
                switch((a[i]==' ')||(a[i]=='\t'))
                {
                    case 1:;
                        w++;
                        c++;
                    break;
                    case 0: 
                        switch((a[i] >= 33 && a[i] <= 47) || (a[i] >= 58 && a[i] <= 64) || (a[i] >= 91 && a[i] <= 96) || (a[i] >= 123 && a[i] <= 126))
                        {
                            case 1:
                                s++;
                                c++;
                            break;
                            case 0:
                                c++;
                            break;
                        }
                }
            break;
        }
    i++;
    }
    printf("Line count = %d\n",l);
    printf("Word count = %d\n",w);
    printf("Character count = %d\n",c);
    printf("Special character count = %d",s);
    
    return 0;
}
