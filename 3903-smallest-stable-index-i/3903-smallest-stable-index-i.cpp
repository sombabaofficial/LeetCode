class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int>maxi(n),mini(n);
        int maxii=nums[0];

        for(int i=0;i<n;i++)
        {
            maxi[i]=max(nums[i],maxii);
            maxii = max(nums[i],maxii);
        }
        int minii=nums[n-1];

        for(int i=n-1;i>=0;i--)
        {
            mini[i]=min(nums[i],minii);
            minii = min(nums[i],minii);
        }

        for(int i=0;i<n;i++)
        {
            int score = maxi[i]-mini[i];
            if(score<=k) return i;
        }

        return -1;
        
    }
};