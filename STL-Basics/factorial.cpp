#include <iostream>
using namespace std;

int main()
{
    double a;
    cin >> a;
    cout << "Factorial of " << a << " = ";
    double i = 1;
    for(a; a > 1; a--){
        i = i*a;
    }
    cout << i;
    return 0;
}


/* ALSO: 
[for(int i; ....) is wrong - we redefine i this way]


#include <iostream>
using namespace std;

int main()
{  int i;
   cin >> i;
   int j = 1;
   cout << "Factorial of " << i << " = "; 
   for (int z = i; z >= 1; z--) {
       j = j*z;
   }
   cout << j;
   return 0;
}

*/