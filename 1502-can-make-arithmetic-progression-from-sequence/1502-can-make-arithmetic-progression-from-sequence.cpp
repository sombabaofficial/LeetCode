class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(begin(arr),end(arr));

        int diff = arr[1]-arr[0];

        int n = arr.size();

        for(int i=1;i<n;i++) if(arr[i]-arr[i-1]!=diff) return false;

        return true;
    }
};