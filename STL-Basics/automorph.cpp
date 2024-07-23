#include <iostream>
#include <math.h>

using namespace std;

int main()
{  int x, n, p=0, l;
   cin >> x;
   n = pow(x, 2);
   cout << "Square of " << x << " = " << n << endl;
   for (int i = x; i>0; i=i/10){
       p++;
    }
   int m = pow(10, p);
   l = n%m; // n%pow(10,p) doesn't work.
   if (x==l) cout << x << " is an automorphic no.";
   else cout << x << " is not an automorphic no.";
   
   return 0;
   }