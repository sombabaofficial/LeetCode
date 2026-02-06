class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        int j=0;
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            int maxi = nums[i];
            int mini = nums[j];

            while(j<i && maxi>(long long)k*mini) j++,mini=nums[j];

            ans=max(ans,i-j+1);

        }

        return n-ans;
        
    }
};