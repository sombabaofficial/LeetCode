class Solution {
public:
    string sortString(string s) {
        int i, j;
        map<char, int> mp;
        string s1 = "";
        string temp = "";
        for(auto it:s) mp[it]++;

        while(s1.length()<s.length())
        {
            for(auto it:mp)
            {
                if(it.second>0)
                {
                    s1 += it.first;
                    mp[it.first]--;
                }
            }
            for(auto it:mp)
            {
                if(it.second>0)
                {
                    temp += it.first;
                    mp[it.first]--;
                }
            }
            reverse(temp.begin(), temp.end());
            s1 += temp;
            temp.clear();
        }
        return s1;
    }
};