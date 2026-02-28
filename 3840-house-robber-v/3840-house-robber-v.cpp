class Solution {
public:

    long long maxAmt(int idx,vector<int>& nums, vector<int>& colors,vector<long long>& dp)
    {
        if(idx==0) return nums[0];
        if(idx<0) return 0;

        if(dp[idx]!=-1) return dp[idx];

        long long take;
        if(colors[idx]==colors[idx-1])
        {
            take=nums[idx]+maxAmt(idx-2,nums,colors,dp);
        }
        else take=nums[idx]+maxAmt(idx-1,nums,colors,dp);

        long long notTake = 0 + maxAmt(idx-1,nums,colors,dp);

        return dp[idx]=max(take,notTake);
    }
    long long rob(vector<int>& nums, vector<int>& colors) {

        int n = nums.size();

        if(n==1) return nums[0];

        vector<long long>dp(n,-1);

        return maxAmt(n-1,nums,colors,dp);
        
    }
};