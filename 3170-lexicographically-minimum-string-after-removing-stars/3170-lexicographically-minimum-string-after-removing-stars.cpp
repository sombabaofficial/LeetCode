class Solution {
public:
    typedef pair<char,int>pi;
    typedef pair<int,char>pii;

    struct cmp{
        bool operator()(pi &a, pi &b)
        {
            if(a.first != b.first) return a.first>b.first;

            return a.second<b.second;
        }
    };


    string clearStars(string s) {

        int n = s.length();

        priority_queue<pi,vector<pi>,cmp>st;

        for(int i=0;i<n;i++)
        {
            if(s[i]!='*')
            st.push({s[i],i});
            else st.pop();
        }

        priority_queue<pii,vector<pii>,greater<pii>>st1;

        while(!st.empty())
        {
            st1.push({st.top().second,st.top().first});
            st.pop();
        }

        string ans="";

        while(!st1.empty())
        {
            ans+=st1.top().second;
            st1.pop();
        }


        return ans;
        
    }
};