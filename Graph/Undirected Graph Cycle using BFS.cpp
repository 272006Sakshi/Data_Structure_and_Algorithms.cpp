class Solution {
  public:

    bool bfs(int u, vector<int> adj[], vector<bool> &visited){
        queue<pair<int, int>> que;
        que.push({u, -1});
        visited[u] = true;
        
        while(!que.empty()){
            pair<int, int> P = que.front();
            que.pop();
            
            int source = P.first;
            int parent = P.second;
            
            for(auto &v: adj[source]){
                if(visited[v] == false){
                    visited[v] = true;
                    que.push({v, source});
                }
                else if(v!=parent){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> adj[V];
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> visited(V, false);
        for(int i=0;i<V;i++){
            if(!visited[i] && bfs(i, adj, visited)) return true;
        }
        return false;
    }
};
