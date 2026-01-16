class Solution {
public:
    bool isPalindrome(string s) {

        string s1;

        for(int i=0;i<s.size();i++)
        {
            if(islower(s[i]))
            s1+=s[i];
            else if (isupper(s[i]))
            s1 += tolower(s[i]);
            else if(s[i]>='0' && s[i]<='9')
            s1+=s[i];

        }

        string s2=s1;

        reverse(s2.begin(),s2.end());

        return s1==s2;

        
    }
};