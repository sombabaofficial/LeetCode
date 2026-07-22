class Solution {
public:
    vector<vector<int>> st;

    vector<vector<int>> zeros_block; 
    vector<int> adj_sum_zero_block; 

    void buildSparseTable() {
        
        int n= adj_sum_zero_block.size();
        if(n==0) return;
        int log = log2(n) + 1;
        st.resize(n, vector<int>(log,0));
        
        for (int i = 0; i < n; i++) {
            st[i][0] = adj_sum_zero_block[i];
        }
    
        for (int j = 1; j < log; j++) {
            for (int i = 0; i + (1 << j) - 1 < n; i++) {
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    
    int query(int L, int R) {
        int length = R - L + 1;
        int log = log2(length);
        return max(st[L][log], st[R - (1 << log) + 1][log]);
    }

    void preprocess_zeros_block(string s){
        int n= s.size();

        for(int i =0;i<s.size();i++){
            char c = s[i];
            if(c=='1') continue;
            
            int x = 0;
            int ix = i;
            while(i!=n && s[i]==c){
                i++;
                x++;
            }
            zeros_block.push_back({ix, i-1, x});
        }
    }
    void preprocess_adj_sum_zero_block(){
        int n = zeros_block.size();
        for(int i=1;i<n;i++){
            adj_sum_zero_block.push_back(zeros_block[i-1][2]+zeros_block[i][2]);
        }
    }

    vector<int> pref1;

    void preprocess_one_range(string s){
        int n=s.size();
        pref1.resize(n,0);
        if(s[0]=='1'){
            pref1[0]=1;
        }
        for(int i =1;i<n;i++){
            pref1[i]+=pref1[i-1]+(s[i]=='1');
        }
    }
    int get_one_range(int l,int r){
        if(l==0){
            return pref1[r]; 
        }
        return pref1[r]-pref1[l-1];
    }

    vector<int> get_zero_block_range(int l,int r){
        int s = 0;
        int e = zeros_block.size()-1;
        int lx = -1;
        int rx = -1;
        
        while(s<=e){
            int m = (s+e)/2;
            
            if(zeros_block[m][1]<l){
                s = m+1;
            }else{
                e = m-1;
                if(zeros_block[m][1]<=r) lx = m;
            }
        }
        s = 0;
        e = zeros_block.size()-1;

        while(s<=e){
            int m = (s+e)/2;
            
            if(zeros_block[m][0]>r){
                e = m-1;
            }else{
                s = m+1;
                if(zeros_block[m][0]>=l) rx = m;
            }
        }
        if(lx==-1) lx = rx;
        if(rx==-1) rx = lx;

        return {lx,rx};
    }

    vector<int> process_query(vector<vector<int>>& queries){
        vector<int> ans;
        
        for(auto &q : queries){
            int l = q[0];
            int r = q[1];
            int total_ones = get_one_range(0,pref1.size()-1);
            int ansx = total_ones;
            
            vector<int> lrx = get_zero_block_range(l,r);
            int lx = lrx[0];
            int rx = lrx[1];
            if(lx==-1 && rx==-1) {
                ans.push_back(ansx);
                continue;
            }
            
            if(zeros_block.size()==0){
                ans.push_back(ansx);
                continue;
            }
            if(rx-lx>2){
               ansx=max(ansx, total_ones + query(lx+1, rx-2));
            }
            int leftover_l = zeros_block[lx][1]-max(l, zeros_block[lx][0])+1;
            int leftover_r = min(r,zeros_block[rx][1])-zeros_block[rx][0]+1;
      
            if(lx==rx){
                ansx=max(ansx, total_ones );
            }
            else if(lx==rx-1){
                ansx=max(ansx, total_ones + leftover_l + leftover_r);
            }
            else {   
                ansx=max(ansx, total_ones + leftover_l + zeros_block[lx+1][2]);
                ansx=max(ansx, total_ones + leftover_r + zeros_block[rx-1][2]);
            }
            ans.push_back(ansx);
        }
        return ans;
    }
    
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        preprocess_one_range(s);
        preprocess_zeros_block(s);
        preprocess_adj_sum_zero_block();
        buildSparseTable();
        return process_query(queries);   
    }
};