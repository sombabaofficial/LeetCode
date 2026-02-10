class Solution {
public:
    int longestBalanced(vector<int>& nums) {

        int n = nums.size();
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> s1;
            unordered_set<int> s2;

            for (int j = i; j < n; j++) {
                if (nums[j] & 1)
                    s2.insert(nums[j]);
                else
                    s1.insert(nums[j]);

                if (s2.size() == s1.size())
                    maxi = max(maxi, j - i + 1);
            }
        }

        return maxi;
    }
};