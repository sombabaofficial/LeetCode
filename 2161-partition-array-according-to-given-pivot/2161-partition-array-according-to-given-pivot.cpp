class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>v1,v2,v;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            if(nums[i]<pivot) v1.push_back(nums[i]);
            else if (nums[i]>pivot) v2.push_back(nums[i]);
        }

        int m = count(nums.begin(),nums.end(),pivot);

        for(auto it : v1) v.push_back(it);
        for(int i=0;i<m;i++) v.push_back(pivot);
        for(auto it : v2) v.push_back(it);

        return v;

    }
};