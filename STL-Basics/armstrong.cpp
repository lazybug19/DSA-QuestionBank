#include <iostream>
#include <math.h>

using namespace std;

int main()
{  int n, j, p=0;
   cin >> n;
   for (int i = n; i>0; i=i/10){
       j = i%10;
       p = p + pow(j, 3);
    }
   if (n==p) cout << n << " is an armstrong no.";
   else cout << n << " is not an armstrong no.";
   
   return 0;
   }