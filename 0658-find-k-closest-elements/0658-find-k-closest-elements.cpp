class Solution {
public:
    typedef pair<int,int>pi;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        int n = arr.size();

        priority_queue<pi,vector<pi>,greater<pi>>st;

        for(int i=0;i<n;i++)
        {
            st.push({abs(x-arr[i]),arr[i]});
        }

        vector<int>ans;

        for(int i=0;i<k;i++)
        {
            ans.push_back(st.top().second);
            st.pop();
        }

        sort(begin(ans),end(ans));

        return ans;
        
    }
};