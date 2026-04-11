class Solution {
public:
    int minimumDistance(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int,vector<int>>mpp;

        for(int i=0;i<n;i++)

            {
                mpp[nums[i]].push_back(i);
            }

        int mini = INT_MAX;

        for (auto it : mpp)
            {
                vector<int>v=it.second;

                if(v.size()<3) continue;

                for(int i=0;i<v.size()-2;i++)
                    {
                        int x = v[i+1]-v[i]+v[i+2]-v[i]+v[i+2]-v[i+1];
                        mini = min(x,mini);
                    }
            }


        if(mini==INT_MAX) return -1;

        return mini;
    }
};