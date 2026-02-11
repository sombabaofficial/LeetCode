struct Item{
    int start;
    int end;
};

class Solution {
public:
    static bool cmp(Item a, Item b)
    {
        return a.end<b.end;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<Item>v;

        for(int i=0;i<n;i++)
        {
            v.push_back({intervals[i][0],intervals[i][1]});
        }

        sort(v.begin(),v.end(),cmp);

        int cnt =1;

        int free=v[0].end;

        for(int i=1;i<n;i++)
        {
            if(v[i].start>=free) cnt++,free=v[i].end;
        }

        return n-cnt;
    }
};


