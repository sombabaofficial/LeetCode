class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, 2*w});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n, 1e9);

        dist[0] = 0;
        pq.push({0, 0}); 

        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(d > dist[node]) continue;

            for(auto &it : adj[node]){
                int neigh = it.first;
                int wt = it.second;

                if(dist[node] + wt < dist[neigh]){
                    dist[neigh] = dist[node] + wt;
                    pq.push({dist[neigh], neigh});
                }
            }
        }

        return (dist[n-1]==1e9?-1:dist[n-1]);
    }
};