class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int>v;

        unordered_map<int,int>mpp;

        int sum = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mpp[grid[i][j]]++;
            }
        }

        for(auto it:mpp)
        {
            if(it.second>1) v.push_back(it.first);
            sum+=it.first;
        }
  
        n=n*m;

        v.push_back((n*(n+1)/2)-sum);

        return v;
    }
};