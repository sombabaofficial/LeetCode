class Solution {
public:
    long long sumAndMultiply(int n) {

        long long sum=0;
        long long ans=0;
        while(n>0)
            {

                long long rem=n%10;
                if(rem!=0){
                ans = 10*ans + rem;
                sum += rem;
                }

                n/=10;
                
                
                
            }
        long long ans1=0;
        while(ans>0)
            {

                long long rem=ans%10;
                
                ans1 = 10*ans1 + rem;

                ans/=10;
                
                
                
            }

        long long res = sum*ans1;


        return res;
    }
};