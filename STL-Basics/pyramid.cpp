#include <iostream>
using namespace std;

int main()
{   int n;
    cin >> n;
    int m = n;
    for (int i=1; i<=n; i++)
    {
        for(int j=m; j>0; j--) //to shift pyramid by "x" spaces, add "x" to j while initializing
        {                      //or above line: for(int j=1; j<=m+x; j--)
            cout << " ";
        }
    m--;
        for(int k=1; k<=i; k++)
        {
            cout << "*";
            for(int l=1; l<=i-1; l++)
            {
                cout << " ";
                break;
            }
            
        }    
    cout << endl;       
    }    
    
   return 0;
}








