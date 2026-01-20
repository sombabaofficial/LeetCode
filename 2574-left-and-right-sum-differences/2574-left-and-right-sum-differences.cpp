class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n),v1(n),v2(n);

        v1[0]=nums[0],v2[n-1]=nums[n-1];

        for(int i=1;i<n;i++) v1[i]=nums[i]+v1[i-1];
        for(int i=n-2;i>=0;i--) v2[i]=nums[i]+v2[i+1];

        for(int i=0;i<n;i++) ans[i]=abs(v1[i]-v2[i]);

        return ans;
        
    }
};