class Solution {
public:
    string reversePrefix(string word, char ch) {
        if(word.find(ch)!=string::npos)
        {
            int j=0;
            while(word[j]!=ch)j++;
            int i=0;
            while(i<j) swap(word[i],word[j]),i++,j--;
        }

        return word;
    }
};