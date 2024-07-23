vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    vector<int> result;
    set<pair<int, int>> st;
    priority_queue<pair<int,pair<int, int>>> pq;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int N=A.size();
    pq.push({A[N-1]+B[N-1],{N-1,N-1}});
    st.insert({N-1,N-1});
    
    for(int k=0; k<C; k++)
    {
        int i=pq.top().second.first;
        int j=pq.top().second.second;
        result.push_back(pq.top().first);
        pq.pop();
        
        if(st.find({i-1,j})==st.end())
        {
            st.insert({i-1,j});
            pq.push({A[i-1]+B[j],{i-1,j}});
        }
        if(st.find({i,j-1})==st.end())
        {
            st.insert({i,j-1});
            pq.push({A[i]+B[j-1],{i,j-1}});
        }
    }
    return result;
}
