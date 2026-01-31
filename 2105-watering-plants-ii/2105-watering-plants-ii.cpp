class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int cnt = 0;
        int n = plants.size();
        int l=0,h=n-1;
        int capA=capacityA,capB=capacityB;

        while(l<h)
        {
            if(plants[l]<=capacityA) capacityA-=plants[l],l++;
            else capacityA=capA,cnt++,capacityA-=plants[l],l++;
            if(plants[h]<=capacityB) capacityB-=plants[h],h--;
            else capacityB=capB,cnt++,capacityB-=plants[h],h--;
        }
        if(l==h)
        {
            if(capacityA<plants[l] && capacityB<plants[l]) cnt++; 
        }
        return cnt;
        
    }
};