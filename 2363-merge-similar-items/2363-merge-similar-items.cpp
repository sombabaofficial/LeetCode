class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {

        vector<vector<int>>v;

        int n = items1.size();
        int m = items2.size();

        map<int,int>mpp;

        for(int i=0;i<n;i++)
        {
            mpp[items1[i][0]]+=items1[i][1];
        }
        for(int i=0;i<m;i++)
        {
            mpp[items2[i][0]]+=items2[i][1];
        }

        for(auto it:mpp)
        {
            v.push_back({it.first,it.second});
        }

        
        return v;
        
    }
};