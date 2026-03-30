class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.length();

        string chk1,chk2,chk3,chk4;

        for(int i=0;i<n;i++)
        {
            if(i&1)
            {
                chk1+=s1[i];
                chk3+=s2[i];
            }
            else
            {
                chk2+=s1[i];
                chk4+=s2[i];
            }
        }

        sort(begin(chk1),end(chk1));
        sort(begin(chk2),end(chk2));
        sort(begin(chk3),end(chk3));
        sort(begin(chk4),end(chk4));

        return (chk1==chk3) && (chk2==chk4);

    }
};