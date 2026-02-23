class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> str;
        int n = s.size();
        for (int i=0;i+k<=n;i++) 
        {
            str.insert(s.substr(i,k));
        }
        if(str.size()==pow(2,k)) return true;
        return false;
    }
};