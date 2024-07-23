class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0, k;
        map<int, int> mp;
        while(i < nums.size())
        {
            if(mp.find(nums[i]) == mp.end())
                mp[nums[i]] = 1;
            else
                mp[nums[i]]++;
            i++;
        }
        map<int, int> :: iterator itr = mp.begin();
        while(itr != mp.end())
        {
            if(itr->second >= 2)
                k = itr->first;
            itr++;
        }

        return k;  
    }
};

/** Approach : Using Set **/
// Time Complexity: O(n)

/*C++ set count() function is used to return the number of elements 
found in the container. Since, the set container does not contain 
any duplicate element, this function actually returns 1 if the 
element with value val is present in the set container or 0 otherwise.*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Create a set...
        unordered_set<int> hset;
        // Traverse all the elements through the loop...
        for(int idx = 0; idx < nums.size(); idx++) {
            // Searches set. if present, it contains duplicate...
            if(hset.count(nums[idx]))
                return true;
            // insert nums[i] in set...
            hset.insert(nums[idx]);
        }
        return false;
    }
};

//remove duplicate

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        for(int i = 0; i < nums.size(); i++) 
        {
            if(s.count(nums[i]))
                continue;
            s.insert(nums[i]);
        }
        nums.clear();
        for(int i:s)
        {
            nums.push_back(i);
        }
        return nums.size();
    }
};