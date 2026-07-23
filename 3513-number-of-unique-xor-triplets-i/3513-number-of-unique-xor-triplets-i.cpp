class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return n;

        int msb=31-__builtin_clz(n); 
        int ans=max(0,(1<<(msb+1)));

        return ans;
    }
};