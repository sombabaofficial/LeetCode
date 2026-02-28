class Solution {
public:
    int fact(int n)
    {
        int res = 1;
        while(n>0)
        {
            res*=n;
            n--;
        }

        return res;
    }
    bool isDigitorialPermutation(int n) {

        int m = n;
        long long sum = 0;

        while(m>0)
        {
            int rem = m%10;
            sum+=fact(rem);
            m/=10;
        }

        string s1=to_string(sum);
        string s2=to_string(n);

        sort(begin(s2),end(s2));
        sort(begin(s1),end(s1));

        return (s1==s2);

        
    }
};