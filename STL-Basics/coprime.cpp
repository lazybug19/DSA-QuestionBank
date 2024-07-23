#include <iostream>
using namespace std;

int main() {
    int x, y, p;
    cin >> x >> y;
    if (y>=x) {
    for (int i=1; i<=x; i++) {
        if ((x%i == 0) && (y%i == 0)) {
        p = i ;}
        }
    }
    else  {
    for (int i=1; i<=y; i++) {
        if ((x%i == 0) && (y%i == 0)) {
        p = i ;}
        }
    }
    cout << "HCF of " << x << " and " << y << " : " << p << endl;
    if (p == 1) 
            cout << x << " and " << y << " are coprimes.";
    return 0;
}


