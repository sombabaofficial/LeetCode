class Solution {
public:

    typedef pair<int,int>pi;
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

        int n = mat[0].size();
        int m = mat.size();

        map<int,int>mpp;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                mpp[i]+=mat[i][j];
            }
        }

        priority_queue<pi,vector<pi>,greater<pi>>pq;

        for(auto it:mpp)
        {
            pq.push({it.second,it.first});
        }

        vector<int>v;

        for(int i=0;i<k;i++)
        {
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;

    }
};