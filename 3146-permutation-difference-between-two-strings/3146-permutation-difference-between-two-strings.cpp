class Solution {
public:
    int findPermutationDifference(string s, string t) {

        unordered_map<char,int>mpp1,mpp2;
        int n = s.length();

        for(int i=0;i<n;i++) mpp1[s[i]]=i;
        for(int i=0;i<n;i++) mpp2[t[i]]=i;

        int sum = 0;

        for(int i=0;i<n;i++)
        {
            sum+= abs(mpp1[s[i]]-mpp2[s[i]]);
        }
        return sum;


        
    }
};