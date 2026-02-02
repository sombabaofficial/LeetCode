class Solution {
public:
    int fillCups(vector<int>& amount) {

        int maxi=max({amount[0],amount[1],amount[2]});
        int mini=min({amount[0],amount[1],amount[2]});
        int midd=amount[0]+amount[1]+amount[2]-maxi-mini;
        int sum=maxi;

        if(maxi>=mini+midd) return maxi;
        else sum += (mini+midd-maxi+1)/2;
        
        
        return sum;
    }
};