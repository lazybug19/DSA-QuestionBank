#include <stdio.h>
#include <string.h>

int main() {
    char usname[200], passwrd[200];
    int low, up, dig, len, special, space, f, strong=0;
    printf("Enter username: ");
    gets(usname);
    while(strong == 0){
        low=0, up=0, dig=0, f=0, space=0, special=0;
        printf("\nEnter a strong password: ");
        gets(passwrd);
        len = strlen(passwrd);
        for (int j=0; j<len; j++)
        {
            if (passwrd[j] == 32)
            f++;
        }
        if (f > 0) 
        {
            printf("Password must not contain space character.");
            strong = 0;
        }
        else
        {
            if (len < 8) 
            {
                printf("Password must contain minimum 8 characters.");
                strong = 0;
            }
            else 
            {
            for (int i=0; i<len; i++)
                {if (passwrd[i] >= 48 && passwrd[i] <= 57)
                    dig ++;
                if (passwrd[i] >= 65 && passwrd[i] <= 90)
                    up ++;
                if (passwrd[i] >= 97 && passwrd[i] <= 122)
                    low ++;
                if ((passwrd[i] >= 33 && passwrd[i] <= 47) || (passwrd[i] >= 58 && passwrd[i] <= 64)
                || (passwrd[i] >= 91 && passwrd[i] <= 96) || (passwrd[i] >= 123 && passwrd[i] <= 126))
                    special ++;
                if (passwrd[i] == 32)
                    space ++;
                }
                if ((dig > 0) && (up > 0) && (low > 0) && (special > 0) && (space == 0))
                    strong = 1;
                else 
                    {strong = 0; 
                    if (dig == 0) 
                        printf("Password should have atleast one digit.");
                    if (up == 0) 
                        printf("Password should have atleast one uppercase letter.");
                    if (low == 0) 
                        printf("Password should have atleast one lowercase letter.");
                    if (special == 0) 
                        printf("Password should have atleast one special character.");
                    if (space != 0) 
                        printf("Password should not have space character.");
                    }
            }
        }
    }
    printf ("Password successfully created!");
    return 0;
}
    
    
