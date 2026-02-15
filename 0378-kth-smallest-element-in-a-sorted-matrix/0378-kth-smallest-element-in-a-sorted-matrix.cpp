class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int>v;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                v.push_back(matrix[i][j]);
            }
        }

        sort(begin(v),end(v));

        return v[k-1];

        
    }
};