class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int>mpp,mpp1;
        for(auto it:arr) mpp[it]++;
        for(auto it:mpp) mpp1[it.second]++;
        for(auto it:mpp1) if(it.second>1) return false;

        return true;


        
    }
};