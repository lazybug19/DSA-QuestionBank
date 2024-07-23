//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void topoSort(int root, stack<int>& st, vector<int>& vis, vector<vector<pair<int,int>>>& adjList)
    {
        vis[root]=1;
        for(auto node: adjList[root])
        {
            if(!vis[node.first]) 
                topoSort(node.first, st, vis, adjList);
        }
        st.push(root);
    }
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<vector<pair<int,int>>> adjList(N);
        for(int i=0; i<M; i++)
            adjList[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            
        vector<int> vis(N, 0);
        stack<int> st;
        for(int i=0; i<N; i++)
            if(!vis[i]) topoSort(i,st,vis,adjList);
            
        vector<int> dist(N, 1e9);
        dist[0]=0;
        while(!st.empty())
        {
            int root=st.top();
            st.pop();
            for(auto node: adjList[root])
            {
                int val=node.first;
                int wt=node.second;
                dist[val]=min(dist[root]+wt, dist[val]);
            }
        }
        for(int i=0; i<N; i++)
        {
            if(dist[i]==1e9) dist[i] = -1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends