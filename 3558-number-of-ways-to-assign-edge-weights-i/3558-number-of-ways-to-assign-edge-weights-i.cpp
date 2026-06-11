class Solution {
public:
    int MOD=1e9+7;

    void dfs(int root,int p,int depth,int &deep,int &node, vector<int> &parent,vector<vector<int>>& adj){
        if(p!=-1){
            depth=depth+1;
            parent[root]=p;
            if(depth>deep){
                deep=depth;
                node=root;
            }
        }
        for(auto ch:adj[root]){
            if(ch!=p){
                dfs(ch,root,depth,deep,node,parent,adj);
            }
        }
    }
    
    int cntEdge(int node,vector<int>& parent){
        if(parent[node]==-1){
            return 0;
        }
        return 1+cntEdge(parent[node],parent);
    }
    
    long long fastPow(long long base,long long m){
        long long res=1;
        while(m){
            if(m&1){
                res=((res%MOD)*(base%MOD))%MOD;
            }
            base=((base%MOD)*(base%MOD))%MOD;
            m=m>>1;
        }
        return res;
    }
    
    long long assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>> adj(n+1);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> parent(n+1,-1);
        int deep=0;
        int node=1;
        dfs(1,-1,0,deep,node,parent,adj);
        int edgeCnt=cntEdge(node,parent);
        return fastPow(2,edgeCnt-1);
    }
};