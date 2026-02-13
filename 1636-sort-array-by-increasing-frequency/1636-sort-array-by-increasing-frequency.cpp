class Solution {
public:
    typedef pair<int,int> pi;
    struct cmp {
        bool operator()(pi a, pi b)
        {
            if(a.first == b.first)
                return a.second < b.second;  
            return a.first > b.first;        
        }
    };
    vector<int> frequencySort(vector<int>& nums) {

        unordered_map<int,int>mpp;

        for(auto it:nums)mpp[it]++;

        priority_queue<pi,vector<pi>,cmp>pq;

        for(auto it : mpp)
        {
            pq.push({it.second,it.first});
        }

        vector<int>ans;

        while(!pq.empty())
        {
            int freq = pq.top().first;
            int num = pq.top().second;
            pq.pop();

            for(int i=0;i<freq;i++) ans.push_back(num);
        }

        return ans;
        
    }
};