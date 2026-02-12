class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        unordered_map<int,int>mpp;
        for(auto it : nums) mpp[it]++;
        for(auto it : mpp) if(it.second==1) sum+=it.first;
        return sum;
        
    }
};