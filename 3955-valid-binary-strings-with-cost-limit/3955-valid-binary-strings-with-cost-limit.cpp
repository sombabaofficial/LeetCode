class Solution {
public:
    vector<string> ans;

    void f(string temp,int cost,int n,int k){

        if(cost>k) return;

        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }

        f(temp+'0',cost,n,k);

        if(temp.size()==0 || temp.back()!='1'){
            f(temp+'1',cost+temp.size(),n,k);
        }

    }

    vector<string> generateValidStrings(int n, int k) {

        f("",0,n,k);

        return ans;

    }
};