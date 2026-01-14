class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        map<int,int>mpp;
        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            int req = target-nums[i];

            if(mpp.count(req)) return {mpp[req],i};

            mpp[nums[i]]=i;
        }

        return {0,0};
        
    }
};