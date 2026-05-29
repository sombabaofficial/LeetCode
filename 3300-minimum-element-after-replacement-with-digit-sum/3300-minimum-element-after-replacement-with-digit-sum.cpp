class Solution {
public:
    int sum (int n)
    {
        int cnt =0;

        while(n>0)
        {
            cnt += n%10;
            n/=10;
        }

        return cnt;
    }
    int minElement(vector<int>& nums) {
        int n = nums.size();

         vector<int>v;

         for(int i=0;i<n;i++)
         {
            v.push_back(sum(nums[i]));
         }

         return *min_element(v.begin(),v.end());
    }
};