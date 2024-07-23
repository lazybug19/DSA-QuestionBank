#include <iostream>

using namespace std;

int main()
{   int z;
    cin >> z;
    cout << "Multiplication table of " << z << " : " << endl;
    for (int i = 1; i <= 10; i++) {
        cout << i << " * " << z <<" = "<< i*z << endl;
   } 
   return 0;
}