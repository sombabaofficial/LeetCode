class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        int preProd=1,suffProd=1;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(preProd==0) preProd=1;
            if(suffProd==0) suffProd=1;
            preProd=preProd*nums[i];
            suffProd=suffProd*nums[n-i-1];
            maxi = max({maxi,preProd,suffProd});
        }
        return maxi;
        
    }
};