/* Euclidean distance calculation : root-over not necessary
   We maintain a max-heap and preserve the bottom most k coordinates so that when we pop out
   its always the cordinates farther apart (not needed to us)
*/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        int n=points.size();
        for(int i=0; i<n; i++)
        {
            int dist=pow(points[i][0], 2)+pow(points[i][1], 2);
            pq.push({dist, points[i]});
            if(pq.size()>k) pq.pop();
        }

        vector<vector<int>> res;
        while(!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
