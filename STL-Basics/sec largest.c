#include <stdio.h>

int main() {
int n, x, y, z;
printf("Type the no. : ");
scanf("%d", &n);
x = n%10;
y = (n/10)%10;
z = (n/100)%10;
if ((x==z)||(z==y)||(y==x)) {
    if (y>z) printf("Second largest is : %d", z);
        else if (z>y) printf("Second largest is : %d", y);
            else if (y>x) printf("Second largest is : %d", x);
                else if ((y=x) && (y=z)) printf("Second largest is : %d", x);
}
else if ((x>y) && (x>z)) {
    if (y>z) printf("Second largest is : %d", y);
    else printf("Second largest is : %d", z);
}
else if ((z>y) && (z>x)) {
    if (y>x) printf("Second largest is : %d", y);
    else printf("Second largest is : %d", x);
}
else if ((y>z) && (y>x)) {
    if (z>x) printf("Second largest is : %d", z);
    else printf("Second largest is : %d", x);
}
    return 0;
}