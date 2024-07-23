//Q. Lily wants to find segments summing to Ron's birth day,  with a length equalling his birth month. 
int birthday(vector<int> s, int d, int m) {
    int ctr = 0, sum = 0;
    for(int i = 0; i < s.size() - m+1; i++){
        sum = 0;
        for(int j = i; j < i+m; j++){
            sum += s[j];
        }
        if(sum == d){
            ctr++;
        }
    }
    return ctr;    
}

//OR

#include <bits/stdc++.h>
using namespace std;

int fun(int *p, int x, int y)
{
    int j = 0, a = 0, k = 0;
    for(int i = 0; *(p + i) != '\0'; i++)
    {   
        if(a < x) 
        {
            a = a + *(p + i);
            k++;
            if((a == x) && (k == y))
            {
                j++;
                k = 1;
                a = *(p + i);
            }
        }
        else
        a = *(p + i - 1);
    }
    cout << j;
    return 0;
}
int main()
{
    int n, d, m;
    cin >> n;
    int c[n];
    for(int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    cin >> d >> m;
    fun(c, d, m);
    return 0;
}


//also


#include <bits/stdc++.h>
using namespace std;

int fun(int *p, int x, int y)
{
    int j = 0, t = 0;
    for(int i = 0; i < y; i++)
    {
        if(*p != '\0')
        j = *(p + i) + j;
        else 
        {
            cout << t;
        }
    }
    if (j == x)
    {
        if (*p != '\0')
        {
            t++;
            cout << t; //new
            return fun(p++, x,  y);
        }
        else return 0;
    }
    else return fun(p++,  x,  y);
}

int main()
{
    int n, d, m;
    cin >> n;
    int c[n];
    for(int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    cin >> d >> m;
    fun(c, d, m);
    return 0;
}