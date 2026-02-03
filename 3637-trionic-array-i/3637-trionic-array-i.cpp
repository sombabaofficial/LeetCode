class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        for (int x = 1; x < n - 2; x++) {
            bool flag1 = 1;
            for (int i = 0; i < x; i++) {
                if (nums[i] >= nums[i + 1]) {
                    flag1 = 0;
                    break;
                }
            }

            if (!flag1) continue;

            for (int y = x + 1; y < n - 1; y++) {
                bool flag2 = 1;
                for (int i = x; i < y; i++) {
                    if (nums[i] <= nums[i + 1]) {
                        flag2 = 0;
                        break;
                    }
                }

                if (!flag2) continue;

                bool flag3 = 1;
                for (int i = y; i < n - 1; i++) {
                    if (nums[i] >= nums[i + 1]) {
                        flag3 = 0;
                        break;
                    }
                }

                if (flag3) return 1;
            }
        }
        return 0;
    }
};
