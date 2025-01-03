class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        return(a[1] > b[1]);
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int count=0, units=0;
        for(int i=0; i<boxTypes.size(); i++)
        {
            if(boxTypes[i][0]<=truckSize)
            {
                units+=boxTypes[i][0]*boxTypes[i][1];
                truckSize-=boxTypes[i][0];
                count+=boxTypes[i][0];
            }
            else
            {
                if(truckSize<boxTypes[i][0])
                    units+=truckSize*boxTypes[i][1];
                break;
            }
        }
        return units;        
    }
};
