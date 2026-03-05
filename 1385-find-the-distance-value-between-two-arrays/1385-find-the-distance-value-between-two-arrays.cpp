class Solution {
public:

    bool isTrue(int x ,vector<int>& arr2, int d )
    {
        int low = 0;
        int high = arr2.size()-1;

        while(low<=high)
        {
            int mid = (high+low)/2;

            if(abs(arr2[mid]-x)<=d) return false;
            else if(arr2[mid]-x>d) high = mid-1;
            else low = mid+1;
        }

        return true;

    }
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {

        int n = arr1.size();

        sort(begin(arr2),end(arr2));

        int cnt = 0;

        for(int i=0;i<n;i++)
        {
            if(isTrue(arr1[i],arr2,d)) cnt++;
        }

        return cnt;
    }
};