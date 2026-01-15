class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {

        int h = hBars.size();
        int v = vBars.size();

        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());

        int cnt1=1,cnt2=1,count1=1,count2=1;

        for(int i=0;i<h-1;i++)
        {
            if(hBars[i+1]-hBars[i]==1) cnt1++;
            else cnt2=max(cnt2,cnt1),cnt1=1;
        }
        cnt2=max(cnt2,cnt1);
        for(int i=0;i<v-1;i++)
        {
            if(vBars[i+1]-vBars[i]==1) count1++;
            else count2=max(count2,count1),count1=1;
        }
        count2=max(count2,count1);


        int l = min(count2,cnt2);

        return (l+1)*(l+1);

    }
};