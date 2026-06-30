class Solution {
public:
    #define ll long long
    int numberOfSubstrings(string s) {
        
        ll n = s.length();
        
        int lastSeen[3]={-1,-1,-1};

        ll cnt=0;

        for (ll i=0;i<n;i++)
        {
            lastSeen[s[i]-'a']=i;

            if(lastSeen[0]!=-1 && lastSeen[1]!=-1 && lastSeen[2]!=-1)
            {
                cnt += 1 + min ({lastSeen[0],lastSeen[1],lastSeen[2]});
            }
        }

        return cnt;


        
    }
};