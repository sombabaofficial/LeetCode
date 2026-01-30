class Solution {
public:
    long long cnt = 0;

    void merge(vector<int>& nums, int l, int m, int r) {
        int j = m + 1;

        // count reverse pairs
        for (int i = l; i <= m; i++) {
            while (j <= r && (long long)nums[i] > 2LL * nums[j])
                j++;
            cnt += (j - (m + 1));
        }

        // normal merge
        vector<int> temp;
        int i = l;
        j = m + 1;

        while (i <= m && j <= r) {
            if (nums[i] <= nums[j])
                temp.push_back(nums[i++]);
            else
                temp.push_back(nums[j++]);
        }

        while (i <= m) temp.push_back(nums[i++]);
        while (j <= r) temp.push_back(nums[j++]);

        for (int k = l; k <= r; k++)
            nums[k] = temp[k - l];
    }

    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;

        int m = l + (r - l) / 2;
        mergeSort(nums, l, m);
        mergeSort(nums, m + 1, r);
        merge(nums, l, m, r);
    }

    int reversePairs(vector<int>& nums) {
        cnt = 0;
        mergeSort(nums, 0, nums.size() - 1);
        return cnt;
    }
};