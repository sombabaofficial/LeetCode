class Solution {
public:
    int cntNos(vector<int>&nums,int mid)
    {
        int lb = lower_bound(begin(nums),end(nums),mid)-nums.begin();
        return nums.size()-lb;
    }
    int specialArray(vector<int>& nums) {

        int n = nums.size();
        sort(begin(nums),end(nums));

        int low = 0;
        int high = nums.size();


        while(low<=high)
        {
            int mid = (high+low)/2;

            if(cntNos(nums,mid)==mid) return mid;
            else if(cntNos(nums,mid)>mid) low = mid+1;
            else high = mid-1;
        }

        return -1;
        
    }
};