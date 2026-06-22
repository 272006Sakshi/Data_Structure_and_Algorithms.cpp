vector<int> bfs(vector<vector<int>> &adj){
  int V = adj.size();
  vector<bool> visited(V, false);
  vector<int> res;
  queue<int> q;

  int source = 0;
  visited[source] = true;
  q.push(source);

  while(!q.empty()){
     int curr = q.front();
     q.pop();
     res.push_back(curr);

     for (int x : adj[curr]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
     }

  }
  return res;
}
