//swapping first half with second half in an array
#include <iostream>
using namespace std;

int main()
{   int y;
    cin >> y;
    int x[y];
    for (int j=0; j<y; j++)
    {
        cin >> x[j];
    }
    if(y%2==0)
    {
        for(int i=0; i<y/2; i++)
        {
            int n=0;
            n=x[i];
            x[i]=x[y/2 + i];
            x[y/2 + i]=n;
        }        
    }
    else
    {
        for(int i=0; i<y/2; i++)
        {
            int n=0;
            n=x[i];
            x[i]=x[y/2 + i + 1];
            x[y/2 + i + 1]=n;
        } 
    }
    for(int k=0; k<y; k++)
        {
            cout << x[k] << " ";
        }
    return 0;
}

