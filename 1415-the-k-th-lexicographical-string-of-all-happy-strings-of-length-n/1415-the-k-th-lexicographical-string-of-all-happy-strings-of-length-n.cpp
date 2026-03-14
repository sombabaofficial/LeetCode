class Solution {
public:
    string getHappyString(int n, int k) {
        if(k>3*(1<<(n-1))) return "";
        vector<vector<int>> mp(3,vector<int>(2));
        mp[0][0]=1;
        mp[0][1]=2;
        mp[1][0]=0;
        mp[1][1]=2;
        mp[2][0]=0;
        mp[2][1]=1;
        int index;
        for(int i=1;i<=3; i++)
        {
            if(k<=i*(1<<(n-1)))
            {
                index=i-1;
                break;
            }
        }
        string ans;
        ans.push_back(index+'a');
        for(int i=n-2; i>=0; i--)
        {
            while(k>(1<<(i+1)))
            {
                k-=(1<<(i+1));
            }
            if(k>(1<<i))
            {
                index=mp[index][1];
            }
            else
            {
                index=mp[index][0];
            }
            ans.push_back(index+'a');
        }
        return ans;
    }
};