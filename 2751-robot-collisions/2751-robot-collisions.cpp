class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        vector<int>v=positions;
        map<int,int>h;
        map<int,char>d;
        map<int,bool>mpp;
        for(int i=0;i<n;i++){
            h[positions[i]]=healths[i];
            d[positions[i]]=directions[i];
            mpp[positions[i]]=true;
        }
        stack<pair<int,int>>st;

        sort(v.begin(),v.end());

        for(int i=0;i<n;i++){

            if(d[v[i]]=='L'){
                if(st.empty()) continue;
                while(!st.empty()){
                pair<int,int>a=st.top();
                
                if(a.first>h[v[i]]){
                    st.pop();
                    mpp[v[i]]=false;
                    st.push({a.first-1,a.second});
                    h[a.second]=a.first-1;
                    break;

                }
                else if(a.first<h[v[i]]){
                    st.pop();
                    mpp[a.second]=false;
                    h[v[i]]--;
                }
                else{
                    st.pop();
                    mpp[a.second]=false;
                    mpp[v[i]]=false;
                    break;
                }
            }
            }
           if(d[v[i]]=='R') st.push({h[v[i]],v[i]});
        }

        vector<int>ans;
        for(int i=0;i<n;i++){
            if(mpp[positions[i]]){
                ans.push_back(h[positions[i]]);
            }
        }
        
        return ans;

        
    }
};