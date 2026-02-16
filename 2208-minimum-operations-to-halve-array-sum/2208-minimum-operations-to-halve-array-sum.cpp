class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double>st;

        double sum = accumulate(begin(nums),end(nums),0.0);
        double target=sum/2;

        int cnt =0;

        for(auto it:nums)st.push(it);

        while(sum>target)
        {
            double x = st.top();
            st.pop();
            x=x/2;
            sum-=x;
            st.push(x);

            cnt++;
        }

        return cnt;
    }
};