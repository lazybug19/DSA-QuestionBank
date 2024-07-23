vector<int> Solution::dNums(vector<int> &A, int B) {
    vector<int> res;
    if (B > A.size()) return res;
    
    map<int, int> mp;
    int dist=0;
    for(int i=0; i<B; i++)
    {
        if(mp[A[i]]==0) dist++;
        mp[A[i]]++;        
    }
    res.push_back(dist); 
    for(int i=B; i<A.size(); i++)
    {
        if(mp[A[i-B]]==1) dist--;
        mp[A[i-B]]--;
        
        if(mp[A[i]]==0) dist++;
        mp[A[i]]++;
        
        res.push_back(dist);
    }
    return res;
}