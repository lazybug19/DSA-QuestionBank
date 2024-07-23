#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int y = n;
//Tree part:
    for (int x=1; x<=3; x++)
    {   
        if(x==1) 
        {
            int m = y;
            for (int i=1; i<=n; i++ )
            {
                for(int j=1; j<=m+40; j++ )
                    {   
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
            n+=2;
        } 
        
        else
        {
            int m = y;
            for (int i=1; i<=n-2; i++ )
            {
                for(int j=1; j<=m-2+40; j++ )
                    {   
                        cout << " ";
                    }
                m--;
                for(int k=1; k<=i+2; k++)
                    {
                        cout << "*";
                        for(int l=1; l<=i-1+2; l++)
                        {
                            cout << " ";
                            break;
                        }
                        
                    }    
                cout << endl;       
            } 
        n+=2;
        }
    }
//Branch/base:
 for (int p=1; p<=y+2; p++)
    {
        for(int s=1; s<=y-2+40; s++)
        {
            cout << " ";
        }
        for (int q=1; q<=3; q++)
        {   
            cout << "*";
            for (int r=1; r<=2; r++)
            {   
                cout << " ";
                break;
            }
        }
        cout << endl;
    }
    
    return 0;
}
