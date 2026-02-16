class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {

        unordered_map<int,vector<int>>mpp;
        int n = nums.size();
        int m = queries.size();

        for(int i=0;i<n;i++)
        {
            mpp[nums[i]].push_back(i);
        }

        vector<int>v(m,-1);

        for(int i=0;i<m;i++)
        {

            int size = mpp[x].size();

            if(size>=queries[i]) v[i]=mpp[x][queries[i]-1]; 


        }

        return v;
        
    }
};