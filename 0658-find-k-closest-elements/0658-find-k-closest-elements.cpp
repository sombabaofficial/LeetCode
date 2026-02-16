class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        int n = arr.size();

        vector<pair<int,int>>v;

        for(int i=0;i<n;i++)
        {
            v.push_back({abs(x-arr[i]),arr[i]});
        }

        sort(begin(v),end(v));

        vector<int>ans;

        int i=0;

        while(k--) 
        {
            ans.push_back(v[i].second);
            i++;
        }

        sort(begin(ans),end(ans));
        return ans;
        
    }
};