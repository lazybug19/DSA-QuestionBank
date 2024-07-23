#include <iostream>

using namespace std;

int main()
{   int n, p, m;
    cin >> n;
    m = n;
    for (n; n > 0; n=n/10) {
        p = (n%10) + p*10;
    }
    if ( p == m )
    cout << m << " is a palindrome."; // if (n == 0 || (n>0 && n%10 == 0)
    else cout << m << " is not a palindrome.";
    return 0;
}
