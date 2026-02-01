class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];

        nums.erase(nums.begin());

        sort(nums.begin(),nums.end());

        sum+=nums[0]+nums[1];

        return sum;

    }
};