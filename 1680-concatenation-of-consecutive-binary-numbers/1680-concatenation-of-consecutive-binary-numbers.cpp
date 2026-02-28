class Solution {
public:
    int MOD = 1e9+7;
    int concatenatedBinary(int n) {

        long long results=0;

        for(int i=1;i<=n;i++)
        {
            int digits=log2(i)+1;

            results = ((results<<digits)%MOD+i)%MOD;

        }

        return results;
        
    }
};