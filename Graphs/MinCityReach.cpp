/*
There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between 
cities fromi and toi, and given the integer distanceThreshold.
Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple 
such cities, return the city with the greatest number.
*/

// modified floyd warshall

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> adjMatrix(n, vector<int>(n, 1e9));
    for(auto x: edges)
    {
        adjMatrix[x[0]][x[1]]=x[2];
        adjMatrix[x[1]][x[0]]=x[2];
    }
    for (int i=0; i<n; i++) adjMatrix[i][i] = 0;
	  
    // i: src, j: dst, k: intermediate
    // k->i->j only works, neither i->j->k nor i->k->j works : gives TLE
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(adjMatrix[i][k]!=1e9 && adjMatrix[k][j]!=1e9 && adjMatrix[i][k]+adjMatrix[k][j]<adjMatrix[i][j])
                    adjMatrix[i][j]=adjMatrix[i][k]+adjMatrix[k][j];
            }
        }
    }
    
    int mn=INT_MAX, res;
    for(int i=0; i<n; i++){
        int cnt=0;
        for(int j=0; j<n; j++){
            if(adjMatrix[i][j]!=1e9 && adjMatrix[i][j]<=distanceThreshold)
                cnt++;
        }
        if(cnt<=mn)
        {
            mn=cnt;
            res=i;
        }
    }
    return res;
    }
};
