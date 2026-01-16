class Solution {
public:
    bool isVowel(char ch)
    {
        ch=tolower(ch);
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') return true;
        return false;
    }
    string reverseVowels(string s) {

        int n=s.length();
        string str;

        for(int i=0;i<n;i++)
        {
            if(isVowel(s[i])) str+=s[i];
        }

        reverse(str.begin(),str.end());

        int j=0;

        for(int i=0;i<n;i++)
        {
            if(isVowel(s[i])) s[i]=str[j],j++;
        }

        return s;

        
    }
};