class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();

        priority_queue<pair<int,int>>pq;
        unordered_map<int,int>mpp;

        for(auto it:arr)mpp[it]++;

        for(auto it:mpp) pq.push({it.second,it.first});

        int cnt=0,ans=0;

        while(!pq.empty())
        {
            cnt+=pq.top().first;pq.pop();ans++;

            if(cnt>=n/2) return ans;
        }

        return 0;

        
    }
};