class Solution {
public:
    bool checkConsonent(char ch)
    {
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||
        ch==' '||ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch=='5'||
        ch=='6'||ch=='7'||ch=='8'||ch=='9'||ch=='0') return false;

        return true;
    }
    bool checkVowel(char ch)
    {
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') return true;

        return false;
    }
        
    int vowelConsonantScore(string s) {

        int n = s.length();
        int cntC=0,cntV=0;
        for(int i=0;i<n;i++)
        {
            if(checkConsonent(s[i]))cntC++; else if(checkVowel(s[i])) cntV++;
        }

        if(cntC>0) return cntV/cntC;

        return 0;
    }
};