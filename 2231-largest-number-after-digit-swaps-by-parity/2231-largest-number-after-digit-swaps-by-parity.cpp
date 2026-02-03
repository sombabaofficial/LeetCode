class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        int n = s.length();
        string s1,s2;

        for(int i=0;i<n;i++)
        {
            if((s[i]-'0')&1)s1+=s[i];
            else s2+=s[i];
        }

        sort(s1.rbegin(),s1.rend());
        sort(s2.rbegin(),s2.rend());
        
        int l=0,h=0;

        for(int i=0;i<n;i++)
        {
            if((s[i]-'0')&1) s[i]=s1[l],l++;
            else s[i]=s2[h],h++;
        }

        int ans = stoi(s);
        return ans;

        
    }
};