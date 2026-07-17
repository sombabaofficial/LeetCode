class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> mp(mx+1);
        for(auto &it: nums) mp[it]++;
        vector<long long> gcdValue(mx+1);
        for(int i=mx; i>=1; i--){
            int c1 = 0;
            long long sub = 0;
            for(int j=i; j<=mx; j+=i){
                c1 += mp[j];
                sub += gcdValue[j];
            }
            gcdValue[i] = 1LL * c1 * (c1 - 1) / 2 - sub;
        }
        for(int i=1; i<=mx; i++) gcdValue[i] += gcdValue[i-1];
        vector<int> ans;
        for(auto &q: queries){
            int lo = 1, hi = mx;
            int val = -1;
            while(lo <= hi){
                int mid = lo + (hi - lo) / 2;
                if(gcdValue[mid] >= (q+1)){
                    val = mid;
                    hi = mid - 1;
                }else lo = mid + 1;
            }
            ans.push_back(val);
        }
        return ans;
    }
};