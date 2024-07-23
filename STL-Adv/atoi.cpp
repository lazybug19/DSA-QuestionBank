class Solution {
public:
    bool check(char n)
    {
        if(n>=48 && n<=57) return true;
        return false;
    }
    int myAtoi(string s) { 
        int flag=0, sz=s.size();
        long long n=0;
        for(int i=0; i<sz; i++)
        {   
            char x=s[i];    
            if(!check(x))    
            {
                if(x==32)
                {
                    if(n==0) continue;
                    else break;
                } 
                else if(x==45 && n==0)
                {
                    if(i+1<sz && check(s[i+1])) flag=1;
                    else break;
                }
                else if(x==43 && n==0)
                {
                    if(i+1<sz && check(s[i+1])) continue;
                    else break;
                }
                else break;
            }
            else  
            {
                if(n<1e11)
                {
                    n=n*10+x-48;
                    if(i+1<sz && !check(s[i+1])) break;
                }
            }                         
        }
        if(n>INT_MAX && flag) return INT_MIN;
        if(n>INT_MAX) return INT_MAX;
        if(flag==1) return n*-1;
        return n;
    }
};   