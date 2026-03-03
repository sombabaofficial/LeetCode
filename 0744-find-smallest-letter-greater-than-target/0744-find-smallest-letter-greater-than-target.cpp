class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        
        int it = upper_bound(letters.begin(),letters.end(),target)-letters.begin();

        if(it==letters.size()) return letters[0];
        return letters[it];
        
    }
};