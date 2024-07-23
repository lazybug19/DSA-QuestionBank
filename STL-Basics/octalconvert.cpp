#include<iostream>
#include<math.h>
using namespace std;

int main()
{   int n, x, m, f, i, y;
    cin >> n;
    m = n;
    f = 0, i = 0, y = 0;
    for(n; n>0; n=n/10){
        x = (n%10);
        if (x >= 8){
        f++;
        }
    }
    if (f == 0) {
        cout <<  m << " is an octal no." << endl;
        for (m; m>0; m=m/10) {
            y = y + (m%10)*pow(8, i);
            i++;
        }
        cout << "Decimal form" << " = " << y;}
    else cout << m << " is not an octal no.";
   return 0;
}

