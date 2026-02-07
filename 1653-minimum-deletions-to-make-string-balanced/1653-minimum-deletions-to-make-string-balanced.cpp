class Solution {
public:
    int minimumDeletions(string s) {
        int x = 0, ans = 0;
        for(auto ch : s) 
        {
            if(ch=='b') x++;
            else if(x>0) 
            {
                x--;
                ans++;
            }
        }   
        return ans;
    }
};