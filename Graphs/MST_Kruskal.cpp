class Solution
{
	public:
	int findPar(int node, vector<int>& par)
	{
	    if(node==par[node]) return node;
	    return par[node]=findPar(par[node], par);
	}
	
	void unionBySize(int u, int v, vector<int>& par, vector<int>& size)
	{
	    int pu=findPar(u, par);
	    int pv=findPar(v, par);
	    if(pu != pv)
	    {
	        if(size[pu]<size[pv])
    	    {
    	        par[pu]=pv;
    	        size[pv]+=size[pu];
    	    }
    	    else
    	    {
    	        par[pv]=pu;
    	        size[pu]+=size[pv];
    	    }
	    }
	}
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> par(V);
	    vector<int> size(V, 1);
	    for(int i=0; i<V; i++) par[i]=i;
	    
	    int mstWt=0;
        vector<pair<int, pair<int, int>>> list;
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                list.push_back({it[1], {i, it[0]}});
            }
        }
        sort(list.begin(), list.end());
        for(auto x: list)
        {
            int wt=x.first;
            int u=x.second.first;
            int v=x.second.second;
            
            if(findPar(u, par) != findPar(v, par))
            {
                mstWt+=wt;
                unionBySize(u, v, par, size);
            }
        }
        return mstWt;
    }
};
