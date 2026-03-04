class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int>row;
        vector<int>col;

        for(int i=0;i<m;i++)
        {
            int cnt = 0;

            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==1) cnt++;
            }

            row.push_back(cnt);
        }
        for(int i=0;i<n;i++)
        {
            int cnt = 0;

            for(int j=0;j<m;j++)
            {
                if(mat[j][i]==1) cnt++;
            }

            col.push_back(cnt);
        }

        int ans=0;
        for(int i=0;i<m;i++)
        {

            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==1 && row[i]==1 && col[j]==1) ans++; 
            }

        }

        return ans;



    }
};