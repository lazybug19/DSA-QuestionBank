#include <iostream>
#include <math.h>
using namespace std;

int main()
{  int n;
   cin >> n;
   cout << "Prime nos. upto " << n << " : " << endl;
    for (int i=2; i<=n; i++){
      int p = 0;
       for(int j=1; j<=sqrt(i); j++){
           if (i%j == 0)
           p++;
       }
       if(p!=2)
       cout << i <<endl;
   }
   return 0;
}

/*
#include <iostream>
using namespace std;

int main()
{  int n;
   cin >> n;
   cout << "Prime nos. upto " << n << " : " << endl;
    for (int i=2; i<=n; i++){
      int p = 0;
       for(int j=1; j<=i/2; j++){
           if (i%j == 0)
           p++;
       }
       if(p==1)
       cout << i <<endl;
   }
   return 0;
}

OR
 
#include <iostream>
using namespace std;

int main()
{  int n;
   cin >> n;
   cout << "Prime nos. upto " << n << " : " << endl;
    for (int i=2; i<=n; i++){
      int p = 0;
       for(int j=1; j<=i; j++){
           if (i%j == 0)
           p++;
       }
       if(p==2)
       cout << i <<endl;
   }
   return 0;
}
*/

