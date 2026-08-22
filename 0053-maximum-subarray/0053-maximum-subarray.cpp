class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum =0,maxi=*min_element(begin(nums),end(nums));
        for(int i=0;i<n;i++) {
            sum+= nums[i];

            maxi = max(maxi,sum);

            if(sum<0) sum = 0;

        }

        return maxi;
    }
};