class Solution {
public:
    bool checkIfPangram(string sentence) {
        int n = sentence.length();
        unordered_map<char,int>mpp;

        for(int i=0;i<n;i++)
        {
            mpp[sentence[i]]++;
        }

        for(char i = 'a';i<='z';i++)
        {
            if(!mpp[i]) return false;
        }
        return true;
        
    }
};