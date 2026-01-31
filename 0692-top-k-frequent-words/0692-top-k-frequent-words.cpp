class Solution {
public:
    static bool cmp(pair<int,string> &a, pair<int,string> &b)
    {
        if(a.first != b.first)
            return a.first > b.first;
        return a.second < b.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        map<string,int>mpp;

        for(int i=0;i<n;i++)
        {
            mpp[words[i]]++;
        }
        vector<pair<int,string>>v;
        for(auto it:mpp)v.push_back({it.second,it.first});

        sort(v.begin(),v.end(),cmp);

        vector<string>ans;

        for(int i=0;i<k;i++)
        {
            ans.push_back(v[i].second);
        }
        
        return ans;
    }
};