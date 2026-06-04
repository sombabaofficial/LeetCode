class Solution {
public:

    int cal (int n)
    {

        string s = to_string(n);
        if(s.length()<3) return 0;

        int cnt=0;

        for (int i=1;i<s.length()-1;i++)
            {
                if((s[i]-'0')>(s[i-1]-'0') && (s[i]-'0')>(s[i+1]-'0') ) cnt++;
                if((s[i]-'0')<(s[i-1]-'0') && (s[i]-'0')<(s[i+1]-'0') ) cnt++;
            }

        return cnt;
    }
    int totalWaviness(int num1, int num2) {
        int ans=0;

        for(int i=num1;i<=num2;i++)
            {
                ans += cal(i);
            }

        return ans;
    }
};