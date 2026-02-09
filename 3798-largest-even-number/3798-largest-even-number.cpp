class Solution {
public:
    string largestEven(string s) {

        string str ="";

        bool flag =0;
        int j;

        int n = s.length();

        for(int i=n-1;i>=0;i--)
        {
            if((s[i]-'0')%2==0) 
            {
                flag =1,j=i;
                break;
            }
        }
        if(flag)
        {
            for(int i=0;i<=j;i++)
            {
                str+=s[i];
            }
        }

        return str;

    }
};