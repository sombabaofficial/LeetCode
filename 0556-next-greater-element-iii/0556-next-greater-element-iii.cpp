class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        string s1 = s;
        next_permutation(s.begin(),s.end());
        
        if(s<=s1) return -1;

        long long ans=stoll(s);
        if (ans > INT_MAX)
        return -1;
        return int(ans);
    }
};