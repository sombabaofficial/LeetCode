class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int>v=nums;

        sort(v.rbegin(),v.rend());

        unordered_map<int,int>mpp;

        int i=0;
        while(k--)
        {
            mpp[v[i]]++;
            i++;
        }

        vector<int>v1;

        for(int i=0;i<n;i++)
        {

            if(mpp[nums[i]])
            {
                v1.push_back(nums[i]);
                mpp[nums[i]]--;
            }

            if(v1.size()==k) break;
        }

        return v1;
        
    }
};