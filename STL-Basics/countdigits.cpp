#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    cout << "The no. of digits in " << n << " = ";
    m = 0;
    for (n; n>0; n=n/10) {
        //if (n%10 >= 0){
        m++;
    }
    cout << m;
    return 0;
}
/*#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    cout << "The no. of digits in " << n << " = ";
    m = 0;
    for (n; n>0; n=n/10) {
        m++;}
    cout << m;
    return 0;
}

ALSO:
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    cout << "The no. of digits in " << n << " = ";
    m = 0;
    while (n>0){
        n = n/10;
        if (n%10 >= 0){
        m++;}
    }
    cout << m;
    return 0;
}
*/