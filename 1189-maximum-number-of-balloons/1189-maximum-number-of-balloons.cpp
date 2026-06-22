class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> balloon, txt;
        int minWord = INT_MAX;

        string s = "balloon";
        for(char c: s){
            balloon[c]++;
        }

        for(char c: text){
            txt[c]++;
        }

        for(auto c: balloon){
            int q = txt[c.first] / balloon[c.first];  
            minWord = min(minWord, q);
        }

        return minWord;
    }
};