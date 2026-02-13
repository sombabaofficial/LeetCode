
class Solution {
public:
    static unordered_map<int,int>mpp;
    static bool cmp(int a , int b)
    {
        if(mpp[a]==mpp[b]) return a>b;
        return mpp[a]<mpp[b];
    }
    vector<int> frequencySort(vector<int>& nums) {
  
        mpp.clear();
        for(auto it:nums)mpp[it]++;

        sort(nums.begin(),nums.end(),cmp);

        return nums;
        
    }
};
unordered_map<int,int> Solution::mpp;