class Solution {
public:
    int numSteps(string s) {
        int n = s.length();
        int ans = 0;
        int cnt = 0;

        for(int i = n - 1; i > 0; i--) {
            int bit = (s[i] - '0') + cnt;

            if(bit == 1) {
                ans += 2;
                cnt = 1;
            } else  ans++;
            
        }

        if(cnt == 1)  ans++;
        

        return ans;
    }
};