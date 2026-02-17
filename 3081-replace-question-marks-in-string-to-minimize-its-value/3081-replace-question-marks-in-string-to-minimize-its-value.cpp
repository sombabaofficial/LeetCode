class Solution {
public:
    typedef pair<int,char>pi;

    string minimizeStringValue(string s) {

        map<char,int>mpp;

        for(char i='a';i<='z';i++)
        {
            mpp[i]=0;
        }

        int n = s.length();

        for(int i=0;i<n;i++)
        {
            if(s[i]!='?') mpp[s[i]]++;
        }

        priority_queue<pi,vector<pi>,greater<pi>>st;

        for(auto it:mpp)
        {
            st.push({it.second,it.first});
        }

        string str="";

        for(int i=0;i<n;i++)
        {
            if(s[i]=='?')
            {
                char ch = st.top().second;
                int fre=st.top().first;
                st.pop();
                str+=ch;
                fre++;
                st.push({fre,ch});
            }


        }

        sort(begin(str),end(str));
        int j=0;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='?')
            {
                s[i]=str[j];
                j++;
            }
        }
        

    return s;
        
    }
};