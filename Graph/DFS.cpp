// T.C: O(V + E)
// S.C: O(V + E)
void dfsRecfun(vector<vector<int> &adj, vector<bool> &visited, int source, vector<int> &res){
  visited[source] = true;
  res.push_back(source);

  for(int &i:adj[source]){
    if(visited[i]==false){
       dfsRecfun(adj, visited, i, res);
    }
  }
}
vector<int> dfs(vector<vector<int>> & adj){
  int V = adj.size();
  vector<bool> visited(V, false);
  vector<int> res;
  dfsRecfun(adj, visited, 0, res);
  return res;
}
