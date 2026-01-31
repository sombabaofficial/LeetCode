class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        int cnt = count(nums.begin(),nums.end(),0);

        if(cnt==0)
        {
            long long ans=1;

            for(int i=0;i<n;i++)
            {
                ans *= nums[i];
            }

            vector<int>v;

            for(int i=0;i<n;i++) v.push_back(ans/nums[i]);


            return v;
        }
        else if(cnt==1)
        {
            long long ans=1;

            for(int i=0;i<n;i++)
            {
                if(nums[i]!=0)
                ans *= nums[i];
            }

            vector<int>v;

            for(int i=0;i<n;i++) 
            {
                if(nums[i]!=0) v.push_back(0);
                else v.push_back(ans);
            }
            return v;
        }

        vector<int>v(n,0);
        return v;
        
    }
};