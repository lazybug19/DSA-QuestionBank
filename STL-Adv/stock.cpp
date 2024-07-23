//Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int d=0, min=prices[0], max=0;
        for(int i=1; i<prices.size(); i++)
        {
            if(prices[i]<=min) min = prices[i];
            else d=prices[i]-min;

            if(d>max) max=d;         
        }
        return max;
    }
};