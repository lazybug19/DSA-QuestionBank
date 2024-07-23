#include <iostream>
#include <math.h>

using namespace std;

int main()
{   int p = 0, f = 0, n;
    cin >> n;
    cout << "The decimal form of " << n << " = ";
    while (n>0)   
    {
        p = p + ((n%10) *  pow(2, f));
        f ++;
        n = n/10;
    }
    cout << p;
    return 0;
}
