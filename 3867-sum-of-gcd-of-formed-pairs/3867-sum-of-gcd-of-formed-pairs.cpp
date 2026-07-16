class Solution {
public:
    long long gcdSum(vector<int>& nums) {

        int n = nums.size();

        if(n==1) return 0;

        vector<int>v(n);
        int maxi = INT_MIN;

        for(int i=0;i<n;i++)
            {
                maxi = max(maxi,nums[i]);

                v[i]=__gcd(nums[i],maxi);

                
            }

        sort(begin(v),end(v));

        long long sum = 0;

        int l=0,r=n-1;

        while(l<r)
            {
                sum+=__gcd(v[l],v[r]);
                l++;r--;
            }

        return sum;

        
        
    }
};