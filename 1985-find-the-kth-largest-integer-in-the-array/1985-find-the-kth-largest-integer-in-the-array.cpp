class Solution {
public:
    
    struct cmp{
        bool operator()(string &s1, string &s2)
        {
            if(s1.length()==s2.length())
            {
                return s1>s2;
            }

            return s1.length()>s2.length();
        }
    };
    string kthLargestNumber(vector<string>& nums, int k) {
        int n = nums.size();
        priority_queue<string,vector<string>,cmp>st;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            st.push(nums[i]);
            cnt++;
            if(cnt>k) st.pop();
            
        }

        return st.top();

    }
};