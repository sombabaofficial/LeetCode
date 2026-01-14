class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mpp;

        for(int i=0;i<nums.size();i++)
        {
            int num = nums[i];
            int to_find = target - num;

            if(mpp.count(to_find))
            return {mpp[to_find],i};

            mpp[num]=i;
        }

        return {-1,-1};

    
    }
};