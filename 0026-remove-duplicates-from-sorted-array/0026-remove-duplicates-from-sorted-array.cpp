class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();
        vector<int>v;
        v.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            if(nums[i]!=v.back()) v.push_back(nums[i]);
        }

        nums.clear();
        nums=v;

        return v.size();
        
    }
};