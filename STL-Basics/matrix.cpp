#include <iostream>

using namespace std;

int main()
{  int l, b;
   cin >> l >> b;
   for (int i = 1; i <= l; i++){
       for (int j = 1; j <= b; j++){
           cout << "*";
       }
            cout << endl;
   }
   return 0;
}


/* #include <iostream>

using namespace std;

int main()
{  int l;
   cin >> l;
   for (int i = 1; i <= l; i++){
       for (int j = 1; j <= i; j++){
           cout << " ";
       }
            cout << "*" << endl;
   }
   return 0;
}
*/

//typical matrix
#include <iostream>
using namespace std;

int main()
{  int l, f, n, inc, c=0;// l:last digit less than, f: first digit, n: no. of elements, inc: increment factor
   cin >> l >> f >> n >> inc;
   for (int i = f; i < l; i+=inc)
   {    c++;
        cout << i;
        for(int j=1; j<n-1; j++)
        {
            cout << " ";
        }
        if(c==n) 
        {
            cout << endl;
            c=0;
        }
    }
   return 0;
}
