class Solution {
  public:
  
   bool dfs(int node, vector<int> adj[], vector<bool> &visited, vector<bool> &inRecursion){
        visited[node] = true;
        inRecursion[node] = true;
        for(int u: adj[node]){
            if(visited[u]==false && dfs(u, adj, visited, inRecursion)){
                return true;
            }
            else if(inRecursion[u] == true){
                return true;
            }
        }
        inRecursion[node] = false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int> adj[V];
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
        }
        vector<bool> visited(V, false);
        vector<bool>inRecursion(V, false);
        for(int i=0;i<V;i++){
            if(!visited[i] && dfs(i, adj, visited, inRecursion)) return true;
        }
        return false;
    }
};
