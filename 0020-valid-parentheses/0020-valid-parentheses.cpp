class Solution {
public:
    bool isValid(string s) {

        stack<char>st;

        int n = s.length();

        for (int i=0;i<n;i++)
        {
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty()) return false;

                if(st.top()=='(' && s[i]==')')
                {
                     st.pop();continue;
                }
                if(st.top()=='{' && s[i]=='}')
                {
                     st.pop();continue;
                }
                if(st.top()=='[' && s[i]==']')
                {
                     st.pop();continue;
                }

                return false;

            }
        }
        return st.empty();
    }
};