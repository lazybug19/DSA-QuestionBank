#include <iostream>

using namespace std;

int main()
{  int n;
   cin >> n;
   cout << "The reciprocal of " << n << " is : ";
   //int p = 0;  ---> garbage value stored if no initiation.
   for (n; n>0 ; n = n/10){
       //int r = n%10;  ---> no need of additional variables.
       p = r + p*10;
      }
      cout << p;
      return 0;
}

/* while loop:

#include <iostream>

using namespace std;

int main()
{  int n, p;
   cin >> n;
   cout << "The reciprocal of " << n << " is : ";
   while (n>0){
       p = n%10 + p*10;
       n = n/10;
      }
      cout << p;
      return 0;
}*/