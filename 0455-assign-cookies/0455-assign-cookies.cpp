class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int r=0;
        int ans=0;
        int cnt=0;
        int i=0;
        while(i<m && r<n)
        {
            if(s[i]>=g[r]) 
            {
                cnt++;r++;
            }
            i++;
        }

        return cnt;
        
    }
};