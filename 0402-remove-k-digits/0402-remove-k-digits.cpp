class Solution {
public:
    string removeKdigits(string s, int k) {
        int n = s.size();
        stack<char>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && k>0 && st.top()>s[i])
            {
                st.pop();k--;
            }
            st.push(s[i]);
        }

        while(k>0) st.pop(),k--;

        if(st.empty()) return "0";

        string str;
        while(!st.empty()) str+=st.top(),st.pop();
        while(str.size()!=0 && str.back()=='0') str.pop_back();
        if(str.empty()) return "0";
        reverse(str.begin(),str.end());
        return str;
        
    }
};