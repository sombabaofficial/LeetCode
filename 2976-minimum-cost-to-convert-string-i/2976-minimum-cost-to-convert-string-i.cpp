class Solution {
public:

vector<int>dijkstra(int src,vector<vector<pair<int,int>>>&adj){

             vector<int>dist(26,INT_MAX);   
             priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; 

             pq.push({0,src});
             dist[src]=0;   

             while(!pq.empty()){
                   int wtt=pq.top().first;
                   int node=pq.top().second;
                   pq.pop();
                   
                   if(wtt>dist[node])continue;

                   for(auto it:adj[node])
                   {           
                               int cost=it.second;
                               int negh=it.first;     
                               if(dist[node]+cost<dist[negh]){
                                     dist[negh]=dist[node]+cost;
                                     pq.push({dist[negh],negh});
                               }
                   }
             }

             return dist;
}
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
                  
                     int n=original.size();

                     vector<vector<pair<int,int>>>adj(26);

                     for(int i=0;i<n;i++)
                     {
                            char u=original[i]-'a';
                            char v=changed[i]-'a';
                            int wtt=cost[i];

                            adj[u].push_back({v,wtt});    
                           
                     }
                      
                    unordered_map<char,vector<int>>mpp;  
                     for(char ch='a';ch<='z';ch++)
                     {
                           if(source.find(ch)!=string::npos){
      
                                     vector<int>dc=dijkstra(ch-'a',adj);
                                     mpp[ch]=dc;
                           }
                     }

                  long long  cnt=0;
                     for(int i=0;i<source.size();i++){
                          
                              vector<int>dist=mpp[source[i]];
                              if(dist[target[i]-'a']==INT_MAX)return -1;
                              cnt+=dist[target[i]-'a'];
                     }

                     return cnt;

                     

    }
};