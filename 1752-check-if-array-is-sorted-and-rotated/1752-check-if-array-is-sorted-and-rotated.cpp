class Solution {
public:
    bool check(vector<int>& nums) {

        vector<int>v;

        int n = nums.size();

        for(auto it : nums) v.push_back(it);
        for(auto it : nums) v.push_back(it);

        int j=n;
        for(int i=0;i<n;i++)
        {
            if(is_sorted(v.begin()+i,v.begin()+j)) return true;
            j++;
        }

        return false;
        
    }
};