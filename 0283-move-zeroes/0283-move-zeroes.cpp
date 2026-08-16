class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ptr = 0;
        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0) nums[ptr]=nums[i],ptr++;
        }


        for(int i=ptr;i<n;i++) nums[i]=0;
    }
};