#include <bits/stdc++.h>
using namespace std;

int birthdayCakeCandles(int *x)
    {
       if (*x == *(x+1))
       {
           return birthdayCakeCandles(++x) + 1;
       }
       else return 1;
    }

int main()
    {   
        int n;
        cin >> n;
        int candles[n];
        for(int i = 0; i < n; i++)
        {
            cin >> candles[i];
        }
        for(int j = 0; j < n - 1; j++)
        {
            for(int k = 0; k < n - j - 1; k++)
            {
                int a = 0; 
                if (candles[k + 1] > candles[k] )
                {
                    a = candles[k];
                    candles[k] = candles[k + 1];
                    candles[k + 1] = a;
                }
                else;
            }
        }
        cout << birthdayCakeCandles(candles);
    }

//function:
#include <bits/stdc++.h>
using namespace std;

int birthdayCakeCandles(int *x)
    {
       if (*x == *(x+1))
       {
           return birthdayCakeCandles(++x) + 1;
       }
       else return 1;
    }
    
int* heights(int *p, int q) // q = n
    {
        int a = 0; 
        if (*(p + 1) > *p)
        {
            a = *p;
            *p = *(p + 1);
            *(p + 1) = a;
            return heights(++p, q);
        }
        else if (*p == '\0')
        {
            return birthdayCakeCandles(p - q)
        }
        else return heights(++p, q);
    }
    
int main()
    {   
        int n;
        cin >> n;
        int candles[n + 1];
        for(int i = 0; i < n; i++)
        {
            cin >> candles[i];
        }
        cout << heights(candles, n);
        return 0;
    }

//
#include <iostream>
using namespace std;

int heights(int *p, int q) // q = n
    {
        static int m = 0;
        if (m < q - 1)
        {   int a = 0; 
            if (*(p + 1) > *p)
            {
                a = *p;
                *p = *(p + 1);
                *(p + 1) = a;
                return heights(++p, q);
            }
            else if (*p == 0)
            {
                m++;
                return heights(p - q - 1, q);//birthdayCakeCandles(p - q);
            }
            else return heights(++p, q);
        }
        else return 0;
    }
    
int main()
{
    int l[5] = {1, 2, 3, 4};
    //int *m = fun(l);
    //cout << m[0] << " " << m[1];
    heights(l, 4);
    cout << l[0] << " " << l[1] << " "<< l[2] << " "<< l[3];
    return 0;
}

//
#include <bits/stdc++.h>
using namespace std;

int heights(int *p, int q) // q = n
    {
        int ctr = 0, max_ = 0;
        for(int i = 0; i < q; i++)
            if (*(p+i) >= max_)
                max_ = *(p+i);

        for(int i = 0; i < q; i++)
            if (*(p+i) == max_)
                ctr++;
           
        return ctr;
    }
   
int main()
    {  
        int n;
        cin >> n;
        int candles[n + 1];
        for(int i = 0; i < n; i++)
        {
            cin >> candles[i];
        }
        int z = heights(candles, n);
        cout <<  z;
        return 0;
    }

