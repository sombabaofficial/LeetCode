class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {

        int n = words.size();
        unordered_map<char,int>mpp,mpp1;

        for(auto it:chars) mpp[it]++;
        int sum=0;

        for(int i=0;i<n;i++)
        {
            string s = words[i];
            int len = s.length();
            mpp1=mpp;
            bool flag = 1;
            for(int j=0;j<len;j++)
            {
                if(mpp1[s[j]]) mpp1[s[j]]--;
                else
                {
                    flag = 0;
                    break;
                }

            }

            if(flag) sum+=len;
        }
        return sum;
    }
};