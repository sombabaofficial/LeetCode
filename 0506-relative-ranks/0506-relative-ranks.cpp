class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();

        if(n==1) return {"Gold Medal"};
        if(n==2)
        {
            if(score[0]>score[1]) return {"Gold Medal","Silver Medal"};
            else return {"Silver Medal","Gold Medal"};
        }

        priority_queue<int,vector<int>,greater<int>>pq;

        for(int i=0;i<n;i++)
        {
            pq.push(score[i]);
        }
        int m=n;
        unordered_map<int,int>mpp;
        while(!pq.empty())
        {
            mpp[pq.top()]=m;
            pq.pop();
            m--;
        }

        vector<string>ans;

        for(int i=0;i<n;i++)
        {
            if(mpp[score[i]]==1) ans.push_back("Gold Medal");
            else if(mpp[score[i]]==2) ans.push_back("Silver Medal");
            else if(mpp[score[i]]==3) ans.push_back("Bronze Medal");
            else ans.push_back(to_string(mpp[score[i]]));
        }
        return ans;
        
    }
};