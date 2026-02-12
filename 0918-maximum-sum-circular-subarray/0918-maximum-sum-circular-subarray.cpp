class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int n = nums.size();

        int minSum=INT_MAX;
        int maxSum=INT_MIN;
        int totalSum=accumulate(nums.begin(),nums.end(),0);
        int sum=0;

        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            minSum=min(minSum,sum);
            if(sum>0) sum=0;
        }

        sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            maxSum=max(maxSum,sum);
            if(sum<0) sum=0;
        }


        if(minSum==totalSum) return maxSum;

        return max(maxSum,totalSum-minSum);
        
    }
};