class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(),nums.end());

        int b = nums[0]*nums[1]*nums[n-1];
        int d = nums[n-3]*nums[n-2]*nums[n-1];


        return max({b,d});

    }
};