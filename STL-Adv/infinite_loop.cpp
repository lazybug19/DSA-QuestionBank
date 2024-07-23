// finding an element if its part of an infinite loop: a number defined by being equal to 1 (where it will stay), or it loops endlessly in a cycle which does not include 1 when starting with any positive integer, replacing the number by the sum of the squares of its digits and repeat the process until the number ends in 1 

class Solution {
public:
    bool isHappy(int n) {
        map<int, int> m;
        int i, j = 0;
        while(n >= 0)
        {
            if(n > 0)
            {
                j = j + pow((n%10), 2);
                n = n/10;
            }
            else if(n == 0)
            { 
                if(j == 1)
                    return true;
                else
                {
                    if(m.find(j)!=m.end())
                        break;
                    i = j;
                    n = i;
                    j = 0;
                    m[i]++;
                }
            }
        }
        return false;
    }
};