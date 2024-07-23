#include <iostream>

using namespace std;

int main() {
    int x;
    cin >> x;
    switch (x) {
       case 1:
       cout << x + 5;
        break;
        case 2:
        cout << x - 5;
        break;
        case 3:
        cout << x / 5;
        break;
        case 4:
        cout << x * 5;
        break;
    }
    return 0;
}
    