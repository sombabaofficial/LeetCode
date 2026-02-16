class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        vector<int>v;

        for(auto it:nums) if(it>0) v.push_back(it);
        
        sort(v.begin(), v.end());

        int target = 1;
        for (int n : v) 
        {
            if (n == target) target++;
             else if (n > target) return target; 
        }
        
        return target;        
    }
};