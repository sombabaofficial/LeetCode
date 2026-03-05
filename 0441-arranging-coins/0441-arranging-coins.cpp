class Solution {
public:
    int arrangeCoins(int n) {

        int low = 1;
        int high = n;

        int ans;

        while(low<=high){
            int mid = low + (high-low)/2;

            long long x = 1LL*mid*1LL*(mid+1)/2;

            if(x<=n)
            {
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }

        return ans;


        
    }
};