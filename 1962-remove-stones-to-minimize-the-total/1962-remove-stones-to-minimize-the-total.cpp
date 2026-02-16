class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {


        priority_queue<int>st;

        int n = piles.size();

        for(int i=0;i<n;i++) st.push(piles[i]);

        while(k--)
        {
            int x = st.top();
            st.pop();
            st.push((x+1)/2);
        }

        int sum = 0;

        while(!st.empty())
        {
            sum+=st.top();
            st.pop();
        }

        return sum;
        
    }
};