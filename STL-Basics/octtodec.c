#include <stdio.h>
#include <math.h>
int convert(long long oct) {
    int dec = 0; int i = 0; int rem;
    while(oct > 0){
        rem = oct % 10;
        oct = oct / 10;
        dec += rem * pow(8,i);
        i++;
    }
    return dec;
}
int main(){
    long long n;
    printf("Enter the octal number: ");
    scanf("%lld", &n);
    printf("%lld in octal = %d in decimal", n, convert(n));
    return 0;
} 