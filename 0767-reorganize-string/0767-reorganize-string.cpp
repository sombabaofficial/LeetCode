class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();

        priority_queue<pair<int,char>>pq;

        unordered_map<char,int>mpp;

        for(auto it:s)mpp[it]++;

        for(auto it:mpp) pq.push({it.second,it.first});

        string ans;

        while(!pq.empty())
        {
            int currCount = pq.top().first;
            char currChar = pq.top().second;
            pq.pop();

            if(ans.length()>0 && ans[ans.length()-1]==currChar) //wo char hum string mein nahi daal sakte
            {
                if(pq.empty()) return "";
                int nextCount = pq.top().first;
                char nextChar = pq.top().second;
                pq.pop();

                ans.push_back(nextChar);nextCount--;
                if(nextCount) pq.push({nextCount,nextChar});
                
            }
            else
            {
                ans.push_back(currChar);currCount--;

            }

             if(currCount) pq.push({currCount,currChar});

        }

        return ans;
        
    }
};