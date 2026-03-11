class Solution {
public:
    int bitwiseComplement(int n) {
        if (n==0) return 1;

        int temp=n;
        int res=0;

        while (temp>0) 
        {
            res=(res<<1)|1;
            temp>>=1;
        }

        return n^res;
    }
};