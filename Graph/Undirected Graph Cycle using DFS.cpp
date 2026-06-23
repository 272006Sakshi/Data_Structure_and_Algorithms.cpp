// Time Complexity: O(V+E)
// Space Complexity: O(V)  
class Solution {
  public:
    bool dfs(int node, int parent, vector<int> adj[], vector<bool> &visited){
        visited[node] = true;
        for(int u: adj[node]){
            if(!visited[u]){
                if(dfs(u, node, adj, visited)) return true;
            }
            else if(u!=parent){
                return true;
            }
        }
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
            if(!visited[i] && dfs(i, -1, adj, visited)) return true;
        }
        return false;
    }
};
