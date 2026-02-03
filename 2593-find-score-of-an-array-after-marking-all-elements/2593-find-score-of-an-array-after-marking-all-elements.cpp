class Solution {
public:
    typedef pair<int,int> pii;
    long long findScore(vector<int>& nums) {
        int n = nums.size();

        priority_queue<pii,vector<pii>,greater<pii>>pq;

        long long score = 0;
        vector<int>visited(n,0);

        for(int i=0;i<n;i++) pq.push({nums[i],i});
        
        while(!pq.empty())
        {
            int canScore = pq.top().first;
            int idx = pq.top().second;     
            pq.pop();  

            if(!visited[idx])
            {
                visited[idx]++;
                score+=canScore;
                if(idx+1<n) visited[idx+1]++;
                if(idx-1>=0) visited[idx-1]++;
            } 
        }

        return score;
        
    }
};