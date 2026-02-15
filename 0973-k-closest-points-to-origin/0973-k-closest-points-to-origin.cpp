class Solution {
public:

    typedef pair<long long,pair<int,int>>pi; 
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        vector<vector<int>>v;


        priority_queue<pi,vector<pi>,greater<pi>>st;

        int n = points.size();

        for(int i=0;i<n;i++)
        {
            long long dis=(long long)(points[i][0]*points[i][0])+
                              (long long)(points[i][1]*points[i][1]);
            st.push({dis,{points[i][0],points[i][1]}});
        }


        while(k--)
        {
            v.push_back({st.top().second.first,st.top().second.second});
            st.pop();
        }




        return v;

        
    }
};