/*
You are given an array of positive integers price where price[i] denotes the price of the ith candy and a positive 
integer k. The store sells baskets of k distinct candies. The tastiness of a candy basket is the smallest absolute 
difference of the prices of any two candies in the basket. Return the maximum tastiness of a candy basket.
*/

class Solution {
public:
    int findCount(vector<int>& prices, int mid)
    {
        // cnt=1 for first candy
        int cnt=1, prev=prices[0], n=prices.size();
        for(int i=1; i<n; i++)
        {
            if(prices[i]-prev >= mid) // mid is the min achieavable difference
            {
                cnt++;
                prev=prices[i];
            }
        }
        return cnt;
    }
    int maximumTastiness(vector<int>& prices, int k) {
        sort(prices.begin(), prices.end());
        int start=1, end=prices[prices.size()-1]-prices[0];
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(findCount(prices, mid)>=k) start=mid+1;
            else end=mid-1;
        }
        return end; // min diff maxmised
    }
};

