class Solution {
public:
    int minimumDistance(vector<int>& nums) {

        int n = nums.size();

        bool flag = 0;
        int mini = INT_MAX;

        for (int i=0;i<n;i++)
            {
                for (int j=i+1;j<n;j++)
                    {
                        if(nums[i]!=nums[j]) continue;

                        for(int k=j+1;k<n;k++)
                            {
                                if(nums[j]==nums[k])
                                {
                                    flag = 1;
                                    int x =  abs(i - j) + abs(j - k) + abs(k - i);
                                    mini = min(mini,x);
                                    
                                }
                            }
                    }
            }

        if(!flag) return -1;
        return mini;
        
    }
};