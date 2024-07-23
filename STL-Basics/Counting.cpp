#include <iostream>
#include <math.h>
using namespace std;
// FOR SUM OF DIGITS TO THE POWER OF THEIR RESP. PLACES IN REVERSE ORDER
int main(){
    /* FOR SUM OF DIGITS TO THE POWER OF THEIR RESP. PLACE
    int i, m, p = 0, f = 0;
    cin >> m;
    for (m; m>0; m=m/10){
        f++;
        i = m%10;
        p = p + pow(i, f);
    }
    cout << p;*/
    int n, i, p = 0, f = 0;
    cin >> n;
    int m = n;
    for (n; n>0; n=n/10){
        f++;
    }
    for (m; m>0; m=m/10){
        i = m%10;
        p = p + pow(i, f);
        f--;
    }
    cout << p;
    return 0;      
}
    

