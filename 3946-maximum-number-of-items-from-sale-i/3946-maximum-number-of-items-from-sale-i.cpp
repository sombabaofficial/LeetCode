class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items,int budget) {
        int n=items.size();
        vector<int> cnt(n,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j&&items[i][0]%items[j][0]==0){
                    cnt[j]++;
                }
            }
        }

        vector<int> dp(budget+1,0);
        int mn=INT_MAX;

        for(int i=0;i<n;i++){
            int price=items[i][1];
            int val=cnt[i]+1;
            mn=min(mn,price);

            for(int j=budget;j>=price;j--){
                dp[j]=max(dp[j],dp[j-price]+val);
            }
        }

        int ans=0;

        for(int i=0;i<=budget;i++){
            ans=max(ans,dp[i]+(budget-i)/mn);
        }

        return ans;
    }
};