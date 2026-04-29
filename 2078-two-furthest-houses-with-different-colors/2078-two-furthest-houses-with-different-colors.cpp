class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int maxi = 0;
        int n = colors.size();

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(colors[i]!=colors[j]) maxi = max(maxi,j-i);
            }
        }

        return maxi;
    }
};