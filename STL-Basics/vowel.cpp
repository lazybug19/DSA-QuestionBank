#include <iostream>

using namespace std;

int main()
{
 char x;
 cin >> x;
 cout << "Letter is: " << x << "\n\n";
 if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
     cout << x << " is a vowel!";
 }
     else {
         cout << x << " is a consonant!";}
   return 0;
}
