class Solution {
public:
    typedef pair<double,pair<int,int>>pi;
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {

        vector<pi>v;

        int n = arr.size();

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                double d = double((double)arr[i]/(double)arr[j]);
                v.push_back({d,{arr[i],arr[j]}});
            }
        }

        sort(v.begin(),v.end());

        return {v[k-1].second.first,v[k-1].second.second};




        
    }
};