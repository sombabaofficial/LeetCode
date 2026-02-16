class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {

        vector<int>ans;

        unordered_map<int,int>mpp;

        for(auto it:nums)mpp[it]++; 

        for(auto it:mpp)
        {
            if(it.second==1 && mpp.count(it.first+1)==0 && mpp.count(it.first-1)==0)
            ans.push_back(it.first);
        }

        return ans;
        
    }
};