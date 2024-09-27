class Solution {
public:
    int findCount(vector<int>& houses, vector<int>& heaters, int mid)
    {
        int i=0, j=0, n=houses.size(), m=heaters.size();
        while(i<n)
        {
            if(j==m) return false;
            int right=heaters[j]+mid, left=heaters[j]-mid;
            if(houses[i]>=left && houses[i]<=right) i++;
            else j++;
        }
        return true;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int mn=0, mx=INT_MIN;

        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        for(int x: houses) mx=max(mx, x);
        for(int x: heaters) mx=max(mx, x);

        while(mn<=mx)
        {
            int mid=mn+(mx-mn)/2; // radius=mid
            if(!findCount(houses, heaters, mid)) 
                mn=mid+1;
            else 
                mx=mid-1;
        }
        return mn;
    }
};
