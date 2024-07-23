#include <iostream>

using namespace std;

int main()
{
   int x, y, z;
   cin >> x >> y >> z; 
   cout << "The 3 nos. are : " << x <<", " << y <<", "<< z << endl;
   if ((x > y) && (x > z)) 
       cout << x << " is the greatest no.";
    else if ((y > x) && (y > z)) 
            cout << y << " is the greatest no."; 
        else if ((z > x) && (z > y)) 
                cout << z << " is the greatest no.";
    else cout << "All are equal";
   return 0;
}
