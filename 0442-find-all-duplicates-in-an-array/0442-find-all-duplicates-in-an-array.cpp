class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int>v;
        unordered_map<int,int>mpp;
        for(auto it:nums) mpp[it]++;
        for(auto it: mpp) if(it.second==2)v.push_back(it.first);

        return v;
    }
};