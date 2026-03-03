class Solution {
public:

    int isPossible(vector<int>&nums,int mid, int k)
    {
        int n=nums.size();
        int sum = 0;
        int cnt=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>mid) return false;
            sum+=nums[i];

            if(sum>mid)
            {
                cnt++;
                sum=nums[i];
            }

            if(cnt>k) return false;
        }

        return true;
    }
    int splitArray(vector<int>& nums, int k) {

        int n = nums.size();

        int low = *min_element(begin(nums),end(nums));

        int high = accumulate(begin(nums),end(nums),0);
        int ans;

        while(low<=high)
        {
            int mid=(high+low)/2;

            if(isPossible(nums,mid,k))
            {
                ans=mid;
                high = mid-1;
            }
            else low=mid+1;
        }

        return ans;
        
    }
};