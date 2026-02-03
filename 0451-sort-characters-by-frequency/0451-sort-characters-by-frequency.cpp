class Solution {
public:
    typedef pair<int,char>pi;
    string frequencySort(string s) {

        int n = s.length();
        unordered_map<char,int>mpp;

        for(auto it:s) mpp[it]++;

        priority_queue<pi>pq;

        for(auto it:mpp)
        {
            pq.push({it.second,it.first});
        }

        string ans="";

        while(!pq.empty())
        {
            ans += string(pq.top().first,pq.top().second);
            pq.pop();
        }
        return ans;


        
    }
};