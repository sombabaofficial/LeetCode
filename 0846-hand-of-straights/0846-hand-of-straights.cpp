class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> mpp;
        for (int it : hand) {
            mpp[it]++;
        }
        
        sort(hand.begin(), hand.end());
        
        for (int i = 0; i < hand.size(); i++) {
            if (mpp[hand[i]] == 0) {
                continue;
            }
            
            for (int j = 0; j < groupSize; j++) {
                int curr = hand[i] + j;
                
                if (mpp[curr] == 0) {
                    return false;
                }
                
                mpp[curr]--;
            }
        }
        
        return true;
    }
};