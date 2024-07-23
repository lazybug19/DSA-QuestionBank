#include <iostream>
#include <math.h>
using namespace std;

int main()
{ float a, b, c, d, x1, x2, x, y;
    cin >> a >> b >> c;
    cout << a << "x^2 + " << b << "x + " << c << endl;
    d = sqrt(b*b - 4*a*c);
    x1 = (-b + d)/2*a;
    x2 = (-b - d)/2*a;
    x = (-b)/2*a;
    y = d/2*a;
    
    if (d > 0)
      { cout << "x1 = " << x1 <<endl;
        cout << "x2 = " << x2; }
            else if (d == 0)
                cout << "x1 = x2 = " << x1;
    else { cout << "x1 = x + iy where x = " << x << " & y = " << y <<endl;
         cout << "x2 = x - iy where x = " << x << " & y = " << y;}
return 0;
    }