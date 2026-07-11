class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> visited;
    vector<int> component;
    void dfs(int n){
        if(visited[n]) return;
        component.push_back(n);
        visited[n] = true;
        for(auto w: graph[n]) if(!visited[w]){
            dfs(w);
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        graph.resize(n); visited.resize(n);
   
        for(auto& e: edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        int ans = 0;
        for(int i = 0; i < n; i++) if(!visited[i]){
            dfs(i); 
            int aux = component.size() - 1;
            bool done = true;
            for(auto& c: component){
                if(graph[c].size() != aux) {
                    done = false; break;
                }
            }
            if(done)ans++;
            component.erase(component.begin(), component.end());
        }

        return ans;
    }
};