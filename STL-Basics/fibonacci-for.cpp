#include <iostream>

using namespace std;

int main()
{
   int x, y, z, i;
   cin >> x >> y >> i;
   z = x + y;
   cout << "First no. = " << x << endl << "Second no. = " << y << endl << endl;
   cout << "Fibonacci Sequence is: " << endl;   
   cout << x << endl << y << endl;
   for (z ; z < i; z = x + y) {
       x = y;
       y = z;
       cout << z << endl;
   }
   return 0;
}